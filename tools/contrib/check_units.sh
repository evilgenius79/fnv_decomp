#!/bin/bash
# Targeted check: build and compare only the named unit sources (comma-separated in $1) against origin/main.
set -euo pipefail
export HOME=/root FNV_MSVC9_ROOT=/home/claude/msvc/sp1 FNV_MSVC9_RTM_ROOT=/home/claude/msvc/rtm FNV_MSVC8_ROOT=/home/claude/msvc/vc8 FNV_MSVC9_PREFIX=/root/wineprefix
REPO=$(cd "$(dirname "$0")/../.." && pwd); BASE=${2:-origin/main}; W=/home/claude/_check; rm -rf "$W"; mkdir -p "$W"
cd "$REPO"; git worktree prune
git worktree add -q --detach "$W/base" "$BASE"; git worktree add -q --detach "$W/scratch" HEAD
python3 -I tools/compare_builds.py plan "$W/base" . --out "$W/plan.json" --max-shards 1 >/dev/null
python3 -I - "$W/plan.json" "$1" <<'PY'
import json,sys
p=json.load(open(sys.argv[1])); want=set(sys.argv[2].split(','))
u=json.load(open('build/units.json'))['units']
idx=[i for i,x in enumerate(u) if x['source'] in want]
p['units']=idx; p['shards']=[idx]; json.dump(p,open(sys.argv[1],'w'),indent=1)
print('checking',len(idx),'units; plan problems:',p['problems'])
PY
python3 -I tools/compare_builds.py shard "$W/scratch" "$(git rev-parse "$BASE")" "$(git rev-parse HEAD)" --plan "$W/plan.json" --shard 0 --out "$W/result.json" --jobs "${JOBS:-2}"
python3 -I tools/compare_builds.py report --plan "$W/plan.json" "$W/result.json" --only-shard 0 || true
git worktree remove --force "$W/base"; git worktree remove --force "$W/scratch"
