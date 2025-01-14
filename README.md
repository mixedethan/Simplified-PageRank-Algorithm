# Simplified PageRank Algorithm

A C++ implementation of the PageRank algorithm **without a damping factor**. This is for educational purposes to understand how PageRank behaves in a pure power-iteration context.

## Features
- Stores a directed graph using adjacency lists
- Computes PageRank over `n` iterations
- Includes several sample test inputs that illustrate various graph structures
- No damping or teleportation — ranks tend to vanish unless there's a closed cycle

## Prerequisites
- C++ compiler (supporting at least C++11)
- Bash (on Windows, consider Git Bash or WSL to run the `.sh` script)

## Usage

### Build
```bash
g++ -std=c++11 src/main.cpp src/AdjacencyList.cpp -o pagerank
