#!/bin/bash

BINARY="./PMergeMe"

echo "size | min | median | max"
echo "-----|-----|--------|----|"

for size in $(seq 1 33); do
    counts=()
    for rep in $(seq 1 10000); do
        # generate random list of $size elements
        args=$(shuf -i 1-10000 -n $size | tr '\n' ' ')
        count=$($BINARY $args 2>/dev/null | grep "Number of comparisons" | awk '{print $NF}')
        if [ -n "$count" ]; then
            counts+=($count)
        fi
    done

    # sort the counts and compute stats
    sorted=($(printf '%s\n' "${counts[@]}" | sort -n))
    n=${#sorted[@]}
    min=${sorted[0]}
    max=${sorted[$((n-1))]}
    median=${sorted[$((n/2))]}

    echo "$size | $min  | $median | $max"
done