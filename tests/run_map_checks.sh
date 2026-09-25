#!/bin/sh
# Checks that so_long and so_long_bonus reject bad input cleanly: "Error" on standard
# error, exit status 1, and no crash. Valid maps open a window, so they are not run here.
# Run from the repository root after building both games.
set -u

tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
failures=0

# Invalid maps written on the fly, one row per line.
printf '11111\n1P0C1\n1110\n11111\n' > "$tmp/not_rectangular.ber"
printf '11111\n1P0C1\n10E01\n11101\n' > "$tmp/open_wall.ber"
printf '11111\n1P0C1\n10001\n11111\n' > "$tmp/no_exit.ber"
: > "$tmp/empty.ber"
# 62 rows of 200 tiles, more than the 9,999-byte map buffer. This used to overflow the stack.
perl -e 'print "1" x 200, "\n"; print "1", "0" x 198, "1\n" for 1 .. 60; print "1" x 200, "\n"' \
    > "$tmp/too_big.ber"

# check <game directory> <description> [arguments...]
check() {
    dir=$1
    what=$2
    shift 2
    status=0
    # perl's alarm is a portable timeout: macOS has no timeout(1).
    err=$(cd "$dir" && perl -e 'alarm 20; exec @ARGV' ./so_long "$@" 2>&1 >/dev/null) || status=$?
    first=$(printf '%s\n' "$err" | head -n 1)
    if [ "$status" -eq 1 ] && [ "$first" = "Error" ]; then
        echo "ok    $dir: $what"
    else
        echo "FAIL  $dir: $what: exit status $status, stderr: $(printf '%s' "$err" | tr '\n' ' ')"
        failures=$((failures + 1))
    fi
}

for dir in so_long so_long_bonus; do
    check "$dir" "no arguments"
    check "$dir" "two arguments" maps/map.ber maps/map.ber
    check "$dir" "wrong extension" maps/map.ber.txt
    check "$dir" "missing file" maps/does_not_exist.ber
    check "$dir" "the repository's invalid example map" maps/map_error.ber
    for map in not_rectangular open_wall no_exit empty too_big; do
        check "$dir" "$map map" "$tmp/$map.ber"
    done
done

if [ "$failures" -ne 0 ]; then
    echo "$failures check(s) failed"
    exit 1
fi
echo "All map checks passed"
