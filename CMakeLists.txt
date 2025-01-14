cmake_minimum_required(VERSION 3.24)
project(PageRankAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageRankAlgorithm src/main.cpp
        src/AdjacencyList.h
        src/AdjacencyList.cpp)
