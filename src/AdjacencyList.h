#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

class AdjacencyList {
private:
    // vertex = website
    unordered_map<string, int> vertexIndex; // Maps vertex names to a unique index
    vector<double> outdegrees;             // stores # of outgoing edges for each vertex
    vector<double> pageRanks;              // stores pagerank for each vertex
    unordered_map<string, vector<string>> edges; // maps each vertex to a list of vertices it points to
    vector<double> sums;
    int numVertices; // total vertices

public:
    AdjacencyList();
    void addEdge(string from, string to);
    void PageRank(int n);
    // helper functions for PageRank
    void initializePageRanks();
    void calculatePageRankIteration();
    void updatePageRanks();
    void resetSums();
    void printPageRanks();
    // more helper functions
    void addVertexIfNeeded(const string& vertex);
    void updateOutdegree(const string& from);
};

#endif
