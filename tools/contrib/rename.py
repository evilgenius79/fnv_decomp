#!/usr/bin/env python3
"""Rename identifiers across the decomp: sources (src/, include/) and build/units.json.

usage: rename.py [--dry] OLD=NEW [OLD=NEW ...]
       rename.py [--dry] --from FILE     (lines "OLD NEW", # comments allowed)

An identifier is replaced only when delimited by non-identifier characters, in source text and inside decorated
names (where the delimiters are '?', '@' and '$'); C names (_name, _name@8, @name@8) are handled too. FUN_x_shell is
therefore untouched by renaming FUN_x.

A unit that already binds the new decorated name (same scope and signature) would end up with one recipe entry fewer,
which the check forbids (the multiset of bound addresses must not change), so in such a unit the identifier is left
alone, in its source and its recipe entry (reported as SKIP).
"""
import argparse, json, os, re, sys
from pathlib import Path
REPO = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--dry', action='store_true')
    ap.add_argument('--from', dest='src')
    ap.add_argument('--files', help='comma-separated unit sources: touch only these files and their recipe entries')
    ap.add_argument('--skipfile', help='lines "path identifier": leave that identifier alone in that unit')
    ap.add_argument('pairs', nargs='*')
    a = ap.parse_args()
    only = set(a.files.split(',')) if a.files else None
    pairs = []
    for p in a.pairs:
        o, n = p.split('=', 1); pairs.append((o, n))
    if a.src:
        for line in open(a.src):
            line = line.split('#', 1)[0].strip()
            if line:
                o, n = line.split()[:2]; pairs.append((o, n))
    for o, n in pairs:
        assert re.fullmatch(r'[A-Za-z_]\w*', o) and re.fullmatch(r'[A-Za-z_]\w*', n), (o, n)
    pat = {o: re.compile(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(o)) for o, _ in pairs}
    cpat = {o: re.compile(r'^([_@])%s(?=(@\d+)?$)' % re.escape(o)) for o, _ in pairs}

    def sub_one(s, o, n):
        return cpat[o].sub(lambda m: m.group(1) + n, pat[o].sub(n, s))

    raw = (REPO / 'build/units.json').read_text()
    u = json.loads(raw)
    # pre-pass: collisions per unit
    skip = {}
    if a.skipfile:
        for line in open(a.skipfile):
            line = line.split('#', 1)[0].split()
            if len(line) >= 2:
                skip.setdefault(line[0], set()).add(line[1])
    for un in u['units']:
        keys = list(un.get('symbols', {}))   # function entries are a separate container and may share a name
        allkeys = set(keys)
        for o, n in pairs:
            for k in keys:
                nk = sub_one(k, o, n)
                if nk != k and nk in allkeys:
                    skip.setdefault(un['source'], set()).add(o)
                    print(f'SKIP {un["source"]}: {o}->{n} would merge with existing {nk}')
                    break
    # sources
    touched = {}
    for root in ('src', 'include'):
        for dp, dn, fns in os.walk(REPO / root):
            for fn in fns:
                if not fn.endswith(('.c', '.cpp', '.h', '.hpp', '.inl', '.inc')):
                    continue
                p = Path(dp, fn)
                rel = p.relative_to(REPO).as_posix()
                if only is not None and rel not in only:
                    continue
                text = p.read_text(encoding='utf-8', errors='surrogateescape')
                new = text; hits = []
                for o, n in pairs:
                    if o in skip.get(rel, ()):
                        continue
                    if o in new:
                        new, k = pat[o].subn(n, new)
                        if k:
                            hits.append((o, n, k))
                if hits:
                    touched[rel] = hits
                    if not a.dry:
                        p.write_text(new, encoding='utf-8', errors='surrogateescape')
    # recipe
    unit_hits = {}
    for un in u['units']:
        if only is not None and un['source'] not in only:
            continue
        sk = skip.get(un['source'], set())

        def sub_sym(s):
            out = s
            for o, n in pairs:
                if o not in sk and o in out:
                    out = sub_one(out, o, n)
            return out
        changed = 0
        for f in un['functions']:
            ns = sub_sym(f['symbol'])
            if ns != f['symbol']:
                f['symbol'] = ns; changed += 1
            if 'fold_aliases' in f:
                fa = [sub_sym(x) for x in f['fold_aliases']]
                if fa != f['fold_aliases']:
                    f['fold_aliases'] = fa; changed += 1
        if 'symbols' in un:
            ns = {}
            for k, v in un['symbols'].items():
                nk = sub_sym(k)
                if nk != k:
                    changed += 1
                if nk in ns:
                    print(f'ERROR {un["source"]}: {nk} appears twice ({ns[nk]} / {v})')
                ns[nk] = v
            un['symbols'] = ns
        if changed:
            unit_hits[un['source']] = changed
    if not a.dry:
        (REPO / 'build/units.json').write_text(json.dumps(u, indent=1, ensure_ascii=False) + '\n')
    print(f'files touched: {len(touched)}')
    for rel, hits in sorted(touched.items()):
        print(f'  {rel}: ' + ', '.join(f'{o}->{n} x{k}' for o, n, k in hits))
    print(f'units touched in units.json: {len(unit_hits)}')
    srcs = {un['source'] for un in u['units']}
    for rel in touched:
        if rel in srcs and rel not in unit_hits:
            print(f'NOTE {rel}: source changed but no names in its recipe entry changed')


if __name__ == '__main__':
    main()
