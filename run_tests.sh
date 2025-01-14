#!/usr/bin/env bash

g++ -std=c++11 src/main.cpp src/AdjacencyList.cpp -o pagerank

for testfile in tests/test_minimal.in tests/test_cycle.in tests/test_star.in tests/test_complex.in
do
    echo "========== Running $testfile =========="
    ./pagerank < "$testfile"
    echo
done
