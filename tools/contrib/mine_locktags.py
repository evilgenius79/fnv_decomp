#!/usr/bin/env python3
"""Find placeholder-named functions whose body contains a "Class::Method(...)" string literal
(lock tags, debug names). Emit TSV: addr, current symbol, tag, src, line, occurrences-in-body."""
import json, re, os, sys, collections
from pathlib import Path
REPO = str(Path(__file__).resolve().parents[2])
u = json.load(open(f'{REPO}/build/units.json'))
# address -> list of (src, symbol)
fnmap = collections.defaultdict(list)
for un in u['units']:
    for f in un['functions']:
        fnmap[f['address'].lower()].append((un['source'], f['symbol']))
TAG = re.compile(r'"((?:[A-Za-z_]\w*::)+~?[A-Za-z_]\w*)\s*(?:\([^"]*\))?[^"]*"')
FNV = re.compile(r'//\s*@fnv\s+(0x[0-9a-fA-F]{8})')
results = []
for src in sorted({s for v in fnmap.values() for s, _ in v}):
    path = f'{REPO}/{src}'
    if not os.path.exists(path):
        continue
    lines = open(path, encoding='utf-8', errors='replace').read().split('\n')
    # walk functions: from an @fnv tag to the closing brace at column 0
    i = 0
    while i < len(lines):
        m = FNV.search(lines[i])
        if not m:
            i += 1; continue
        addr = m.group(1).lower()
        # body: from first line starting with '{' after tag to line == '}'
        j = i + 1
        while j < len(lines) and not lines[j].startswith('{'):
            if FNV.search(lines[j]): break
            j += 1
        k = j + 1
        tags = collections.Counter()
        while k < len(lines) and not lines[k].startswith('}'):
            for t in TAG.findall(lines[k]):
                tags[t] += 1
            k += 1
        if tags:
            syms = [s for sr, s in fnmap.get(addr, []) if sr == src]
            sym = syms[0] if syms else '?'
            for t, n in tags.items():
                results.append((addr, sym, t, src, i + 1, n))
        i = k + 1 if k > i else i + 1
ph = [r for r in results if 'FUN_' in r[1] or 'Twin_' in r[1]]
print(f'# total functions with Class::Method() string literal: {len(set((r[0],r[3]) for r in results))}; placeholder-named: {len(set((r[0],r[3]) for r in ph))}', file=sys.stderr)
for r in sorted(results):
    print('\t'.join(map(str, r)))
