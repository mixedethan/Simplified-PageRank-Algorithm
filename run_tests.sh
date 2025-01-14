#!/usr/bin/env bash

g++ -std=c++11 main.cpp AdjacencyList.cpp -o pagerank

for testfile in test_minimal.in test_cycle.in test_star.in test_complex.in
do
    echo "========== Running $testfile =========="
    ./pagerank < "$testfile"
    echo
done
