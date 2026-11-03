#!/bin/bash
# Run the project's own pull-request check locally: compare the working tree's HEAD against origin/main.
# usage: check.sh [BASE_REF]      (default origin/main). Commit your change first.
set -euo pipefail
export HOME=/root
export FNV_MSVC9_ROOT=/home/claude/msvc/sp1 FNV_MSVC9_RTM_ROOT=/home/claude/msvc/rtm FNV_MSVC8_ROOT=/home/claude/msvc/vc8
export FNV_MSVC9_PREFIX=/root/wineprefix
REPO=$(cd "$(dirname "$0")/../.." && pwd)
BASE=${1:-origin/main}
W=/home/claude/_check; rm -rf "$W"; mkdir -p "$W"
cd "$REPO"
git worktree prune
git worktree add -q --detach "$W/base" "$BASE"
git worktree add -q --detach "$W/scratch" HEAD
python3 -I tools/compare_builds.py plan "$W/base" . --out "$W/plan.json" --max-shards 1
python3 -I - "$W/plan.json" <<'EOF'
import json,sys
p=json.load(open(sys.argv[1]))
print('code_changed:',p['code_changed']); print('comment_only:',p['comment_only']); print('problems:',p['problems'])
print('units to build:',len(p['units']),'compilers:',p['compilers'])
EOF
if [ "$(python3 -I -c "import json;print(len(json.load(open('$W/plan.json'))['units']))")" != 0 ]; then
  python3 -I tools/compare_builds.py shard "$W/scratch" "$(git rev-parse "$BASE")" "$(git rev-parse HEAD)" \
      --plan "$W/plan.json" --shard 0 --out "$W/result.json" --jobs "${JOBS:-4}"
  python3 -I tools/compare_builds.py report --plan "$W/plan.json" "$W/result.json"
else
  python3 -I tools/compare_builds.py report --plan "$W/plan.json"
fi
git worktree remove --force "$W/base"; git worktree remove --force "$W/scratch"
