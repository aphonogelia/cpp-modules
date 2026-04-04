#!/bin/bash

BINARY="./PMergeMe"

echo "size | min | median | max | sorted_ok"
echo "-----|-----|--------|-----|----------"

for size in $(seq 5 33); do
    counts=()
    sorted_fails=0

    for rep in $(seq 1 500); do
        # generate random list of $size elements
        args=$(shuf -i 1-10000 -n $size | tr '\n' ' ')
        output=$($BINARY $args 2>/dev/null)

        count=$(echo "$output" | grep "Number of comparisons" | awk '{print $NF}')
        if [ -n "$count" ]; then
            counts+=($count)
        fi

        # extract sorted output and verify it is sorted
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
        if [ $ok -eq 0 ]; then
            sorted_fails=$((sorted_fails + 1))
        fi
    done

    # sort the counts and compute stats
    sorted_counts=($(printf '%s\n' "${counts[@]}" | sort -n))
    n=${#sorted_counts[@]}
    min=${sorted_counts[0]}
    max=${sorted_counts[$((n-1))]}
    median=${sorted_counts[$((n/2))]}

    if [ $sorted_fails -eq 0 ]; then
        sorted_ok="OK"
    else
        sorted_ok="FAIL($sorted_fails)"
    fi

    echo "$size | $min | $median | $max | $sorted_ok"
done