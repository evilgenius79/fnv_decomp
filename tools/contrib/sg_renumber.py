#!/usr/bin/env python3
"""Renumber the compiler's string-literal labels ($SGnnnn) in build/units.json for units whose numbering shifted.

usage: sg_renumber.py BASE_TREE HEAD_TREE UNIT_SOURCE [UNIT_SOURCE...]

Compiles each unit at BASE_TREE (main) and HEAD_TREE (the change), reads the $SG symbols of both objects and pairs them
by literal content and order of appearance; then rewrites the unit's recipe entry in HEAD_TREE/build/units.json so each
bound $SG name becomes its counterpart. Only names change; the addresses they bind do not.
"""
import json, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from compare import Coff  # noqa: E402

base, head = Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve()
units = sys.argv[3:]
recipe_path = head / 'build/units.json'
recipe = json.loads(recipe_path.read_text())
by_source = {u['source']: u for u in recipe['units']}


def compile_unit(tree, unit, obj):
    r = subprocess.run([sys.executable, str(tree / 'tools/msvc.py'), '--compiler', unit['compiler'], '/c', '/nologo']
                       + unit['flags'] + ['/I' + str(tree / 'include'), str(tree / unit['source']), '/Fo' + str(obj)],
                       cwd=tree, capture_output=True, text=True, errors='replace')
    if r.returncode or not obj.exists():
        raise SystemExit('compile failed in %s: %s' % (tree, r.stdout[-2000:]))


def sg_symbols(obj):
    """[(name, content)] for the $SG symbols, in numeric order."""
    coff = Coff(obj)
    out = []
    for s in coff.symbols.values():
        if re.fullmatch(r'\$SG\d+', s['name']) and s['section'] > 0:
            sec = coff.sections[s['section']]['data']; start = s['value']
            end = sec.find(b'\0', start)
            out.append((int(s['name'][3:]), s['name'], sec[start:end + 1 if end >= 0 else len(sec)]))
    out.sort()
    return [(n, c) for _, n, c in out]


changed_total = 0
with tempfile.TemporaryDirectory() as tmp:
    for src in units:
        unit = by_source[src]
        a, b = Path(tmp, 'a.obj'), Path(tmp, 'b.obj')
        compile_unit(base, unit, a); compile_unit(head, unit, b)
        sa, sb = sg_symbols(a), sg_symbols(b)
        if len(sa) != len(sb):
            print('%s: %d $SG symbols at base, %d at head; not the same literals' % (src, len(sa), len(sb)))
            continue
        # pair by content, k-th occurrence with k-th occurrence
        from collections import defaultdict
        pa, pb = defaultdict(list), defaultdict(list)
        for n, c in sa: pa[c].append(n)
        for n, c in sb: pb[c].append(n)
        mapping = {}
        ok = True
        for c, names in pa.items():
            if len(pb.get(c, [])) != len(names):
                print('%s: literal %r appears %d times at base, %d at head' % (src, c[:40], len(names), len(pb.get(c, []))))
                ok = False; break
            for x, y in zip(names, pb[c]):
                mapping[x] = y
        if not ok:
            continue
        changed = 0
        new = {}
        for k, v in unit.get('symbols', {}).items():
            nk = mapping.get(k, k)
            if nk != k:
                changed += 1
            new[nk] = v
        if len(new) != len(unit.get('symbols', {})):
            print('%s: renumbering would merge entries; left alone' % src); continue
        unit['symbols'] = new
        for f in unit['functions']:
            if 'fold_aliases' in f:
                f['fold_aliases'] = [mapping.get(x, x) for x in f['fold_aliases']]
        shifts = sorted({mapping[k] != k for k in mapping})
        print('%s: %d $SG names renumbered (%d literals)' % (src, changed, len(sa)))
        changed_total += changed
recipe_path.write_text(json.dumps(recipe, indent=1, ensure_ascii=False) + '\n')
print('done: %d names changed' % changed_total)
