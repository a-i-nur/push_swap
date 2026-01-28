#!/usr/bin/env bash
set -u

PS_BIN="./push_swap"
CHK_BIN="./checker"

need_bin() {
  if [ ! -x "$1" ]; then
    make -s >/dev/null || return 1
    make -s bonus >/dev/null || return 1
  fi
  return 0
}

run_valgrind() {
  local name="$1"; shift
  echo "== $name =="
  valgrind --leak-check=full --show-leak-kinds=all "$@"
  echo
}

main() {
  need_bin "$PS_BIN" || { echo "build failed"; exit 1; }
  need_bin "$CHK_BIN" || { echo "build failed"; exit 1; }

  run_valgrind "sorted small" "$PS_BIN" 1 2 3 4 5
  run_valgrind "reverse small" "$PS_BIN" 5 4 3 2 1
  run_valgrind "two elems" "$PS_BIN" 2 1
  run_valgrind "already sorted 10" "$PS_BIN" 1 2 3 4 5 6 7 8 9 10
  run_valgrind "single-arg list" "$PS_BIN" "3 1 2 5 4"
  run_valgrind "int min/max" "$PS_BIN" -2147483648 2147483647 0 -1 1

  run_valgrind "invalid alpha" "$PS_BIN" 1 a 2
  run_valgrind "invalid sign only" "$PS_BIN" +
  run_valgrind "invalid double sign" "$PS_BIN" --1
  run_valgrind "invalid empty string" "$PS_BIN" ""
  run_valgrind "invalid spaces only" "$PS_BIN" "   "
  run_valgrind "valid spaces mixed" "$PS_BIN" "1   2  3"
  run_valgrind "duplicate" "$PS_BIN" 1 2 2
  run_valgrind "overflow" "$PS_BIN" 2147483648

  echo "== checker pipeline 100 =="
  ARG100="$(python3 - <<'PY'
import random
print(" ".join(map(str, random.sample(range(-1000000, 1000000), 100))))
PY
)"
  OPS100="$($PS_BIN $ARG100)"
  printf "%s" "$OPS100" | valgrind --leak-check=full --show-leak-kinds=all "$CHK_BIN" $ARG100

  echo "== checker pipeline 500 =="
  ARG500="$(python3 - <<'PY'
import random
print(" ".join(map(str, random.sample(range(-1000000, 1000000), 500))))
PY
)"
  OPS500="$($PS_BIN $ARG500)"
  printf "%s" "$OPS500" | valgrind --leak-check=full --show-leak-kinds=all "$CHK_BIN" $ARG500
}

main "$@"
