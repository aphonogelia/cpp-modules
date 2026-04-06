#!/bin/bash

BINARY="./PMergeMe"
REPS=1000


printf "%-6s %-8s %-8s %-8s %-8s %-8s %-12s\n" \
    "size" "min" "mean" "max" "F(n)" "lg(n!)" "sorted"
printf "%-6s %-8s %-8s %-8s %-8s %-8s %-12s\n" \
    "------" "--------" "--------" "--------" "--------" "--------" "------------"
FN=(0 0 1 3 5 7 10 13 16 19 22 26 30 34 38 42 46 50 54 58 62 66 71 76 81 86 91 96 101 106 111 116 121 126)

lgfact() {
    python3 -c "import math; n=$1; print(math.ceil(math.log2(math.factorial(n))) if n > 1 else 0)"
}

for size in $(seq 1 33); do
    counts=()
    sorted_fails=0
    total=0

    for rep in $(seq 1 $REPS); do
        args=$(shuf -i 1-10000 -n $size | tr '\n' ' ')
        output=$($BINARY $args 2>/dev/null)

        # grab vector comparison count
        count=$(echo "$output" | grep "comparisons (vector)" | awk -F: '{print $2}' | tr -d ' ')
        if [ -n "$count" ]; then
            counts+=($count)
            total=$((total + count))
        fi

        # verify sorted output
        sorted_line=$(echo "$output" | grep "^Sorted:" | sed 's/Sorted: //')
        count_out=$(echo "$sorted_line" | wc -w)
        prev=""
        ok=1
        if [ "$count_out" -ne "$size" ]; then
            ok=0
        fi
        for val in $sorted_line; do
            if [ -n "$prev" ] && [ "$val" -lt "$prev" ]; then
                ok=0
                break
            fi
            prev=$val
        done
        [ $ok -eq 0 ] && sorted_fails=$((sorted_fails + 1))
    done

    sorted_counts=($(printf '%s\n' "${counts[@]}" | sort -n))
    n=${#sorted_counts[@]}
    min=${sorted_counts[0]}
    max=${sorted_counts[$((n-1))]}
    mean=$((total / n))

    fn_val=${FN[$size]}
    lgfact_val=$(lgfact $size)

    if [ $sorted_fails -eq 0 ]; then
        sorted_ok="OK"
    else
        sorted_ok="FAIL($sorted_fails)"
    fi

    # flag if max exceeds F(n)
    flag=""
    if [ "$max" -gt "$fn_val" ] 2>/dev/null; then
        flag=" !"
    fi

    printf "%-6s %-8s %-8s %-8s %-8s %-8s %-12s\n" \
        "$size" "$min" "$mean" "$max$flag" "$fn_val" "$lgfact_val" "$sorted_ok"
done