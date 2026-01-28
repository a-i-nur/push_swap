#!/usr/bin/env bash
set -u

PS_BIN="./push_swap"
CHK_BIN="./checker"

RED=""; GREEN=""; YELLOW=""; RESET=""
if [ -t 1 ]; then
  RED="$(printf '\033[31m')"
  GREEN="$(printf '\033[32m')"
  YELLOW="$(printf '\033[33m')"
  RESET="$(printf '\033[0m')"
fi

ok() { printf "%sOK%s %s\n" "$GREEN" "$RESET" "$1"; }
warn() { printf "%sWARN%s %s\n" "$YELLOW" "$RESET" "$1"; }
fail() { printf "%sFAIL%s %s\n" "$RED" "$RESET" "$1"; }

need_bin() {
  if [ ! -x "$1" ]; then
    warn "$1 not found, building..."
    make -s >/dev/null || return 1
    make -s bonus >/dev/null || return 1
  fi
  return 0
}

expect_error() {
  local name="$1"; shift
  local out
  out="$("$PS_BIN" "$@" 2>&1 >/dev/null || true)"
  if printf "%s" "$out" | grep -q "Error"; then
    ok "$name"
  else
    fail "$name (expected Error)"
  fi
}

expect_ok() {
  local name="$1"; shift
  local ops chk
  ops="$("$PS_BIN" "$@")"
  chk="$(printf "%s" "$ops" | "$CHK_BIN" "$@" | tr -d '\n')"
  if [ "$chk" = "OK" ]; then
    ok "$name"
  else
    fail "$name (checker=$chk)"
  fi
}

bench() {
  local n="$1"
  local limit="$2"
  local runs="${3:-10}"
  local i=1
  local max=0
  local okc=0
  while [ "$i" -le "$runs" ]; do
    local arr ops cnt chk
    arr="$(python3 - <<PY
import random
print(" ".join(map(str, random.sample(range(-1000000, 1000000), $n))))
PY
)"
    ops="$($PS_BIN $arr)"
    cnt=$(printf "%s" "$ops" | wc -l | tr -d ' ')
    chk="$(printf "%s" "$ops" | "$CHK_BIN" $arr | tr -d '\n')"
    [ "$chk" = "OK" ] && okc=$((okc+1))
    [ "$cnt" -gt "$max" ] && max="$cnt"
    if [ "$cnt" -le "$limit" ] && [ "$chk" = "OK" ]; then
      ok "bench $n run $i: $cnt"
    else
      fail "bench $n run $i: $cnt (checker=$chk, limit=$limit)"
    fi
    i=$((i+1))
  done
  printf "bench %s summary: OK=%s/%s max=%s limit=%s\n" "$n" "$okc" "$runs" "$max" "$limit"
}

main() {
  need_bin "$PS_BIN" || { fail "build failed"; exit 1; }
  need_bin "$CHK_BIN" || { fail "build failed"; exit 1; }

  echo "basic validity"
  expect_ok "sorted small" 1 2 3 4 5
  expect_ok "reverse small" 5 4 3 2 1
  expect_ok "mixed small" 3 1 4 2 5
  expect_ok "two elems" 2 1

  echo "error cases"
  expect_error "duplicate" 1 2 2
  expect_error "alpha" 1 a 2
  expect_error "overflow" 2147483648
  expect_error "empty arg" ""

  echo "benchmarks"
  bench 100 700 10
  bench 500 5500 10
}

main "$@"
