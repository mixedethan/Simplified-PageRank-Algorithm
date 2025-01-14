# Simplified PageRank Algorithm

A C++ implementation of the infamous PageRank algorithm **without a damping factor**. This is for educational purposes to understand how PageRank operates.

## Features
- Stores a directed graph using adjacency lists.
- Allows an **interactive** prompt for entering edges and specifying how many iterations to run.
- Can be tested with provided input files that illustrate common graph scenarios:
    - Minimal edge
    - 3-node cycle
    - Star graph
    - Mixed & partially leaking graph
- Easy Bash script (`run_tests.sh`) compiles and runs the project against pre-made sample tests.

## Prerequisites
- C++ compiler (supporting at least C++11)
- **Bash** shell (macOS has this by default, though it might be Zsh — still works for script execution).


## Repository Sturcture
    Simplified-PageRank-Algorithm/
    ├── src/
    │   ├── main.cpp
    │   ├── AdjacencyList.h
    │   ├── AdjacencyList.cpp
    ├── tests/
    │   ├── test_minimal.in
    │   ├── test_cycle.in
    │   ├── test_star.in
    │   └── test_complex.in
    ├── run_tests.sh
    └── README.md

## Usage

### Build Instructions

From the **root** directory (where `run_tests.sh` and the `src/` folder are located), run:

```bash
g++ -std=c++11 src/main.cpp src/AdjacencyList.cpp -o pagerank

# To run in interactive mode:
./pagerank

# The program will prompt you for:
# 1) Number of edges
# 2) Number of iterations
# 3) Each edge in the format "FROM TO"

# You can also run from a test input file:
./pagerank < tests/test_cycle.in

# Finally you can run all the provided tests:

# Make the script executable (one-time step):
chmod +x run_tests.sh
# Be sure to check your permissions for using chmod


# Run the script:
./run_tests.sh
```

### Example Output
```bash
Welcome to the Simple PageRank Algorithm!
How many edges will you provide? 3
How many iterations of PageRank would you like to run? 10
Please enter 3 edges in the format: FROM TO
A B
B C
C A
```


## Thank you for checking out my project! 🚀
