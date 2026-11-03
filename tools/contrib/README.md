# Contributor helpers (not part of the check)

Scripts used to prepare the renaming pull requests; they assume the compilers are set up as README.md describes.

- `rename.py OLD=NEW ...` / `--from FILE`: rename identifiers in `src/`, `include/` and the decorated names in
  `build/units.json` (word-delimited, so `FUN_x_shell` survives renaming `FUN_x`; C names `_name`/`@name@8` too).
  Leaves an identifier alone in a unit where the new decorated name already binds the same address (the check
  forbids merging recipe entries); `--skipfile` adds such exceptions by hand, `--files` restricts a run.
- `sg_renumber.py BASE HEAD UNIT...`: when a rename shifts the compiler's `$SGnnnn` string labels in a unit (it
  happens when the new identifier already existed in the unit), builds the unit at both trees and rebinds the
  labels in the recipe by literal content.
- `mine_locktags.py`: lists placeholder-named functions whose body passes a `"Class::Method()"` string to a lock
  or timer helper: the game's own name for the function.
- `check.sh` / `check_units.sh UNIT,...`: run `tools/compare_builds.py` locally against `origin/main` for the whole
  change, or for the named units only. Edit the paths at the top for your setup.
