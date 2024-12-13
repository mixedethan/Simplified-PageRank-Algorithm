/*
 *      Simplified PageRank Algorithm
 *            by Ethan Wilson
 *             11/9/2023
 *
 */

#include<iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iomanip>
using namespace std;

class AdjacencyList {
private:
    // vertex = website
    unordered_map<string, int> vertexIndex; // Maps vertex names to a unique index
    vector<double> outdegrees; // stores # of outgoing edges for each vertex
    vector<double> pageRanks; // stores pagerank for each vertex
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

AdjacencyList::AdjacencyList() {
    numVertices = 0;
}

void AdjacencyList::addVertexIfNeeded(const string& vertex) {
    // if the vertex isn't in the graph add it in
    if (vertexIndex.find(vertex) == vertexIndex.end()) {
        vertexIndex[vertex] = numVertices++;
        outdegrees.push_back(0.0);
        pageRanks.push_back(0.0);
        sums.push_back(0.0);
    }
}

void AdjacencyList::updateOutdegree(const string& from) {
    // increment outdegree count for the "from: vertex
    outdegrees[vertexIndex[from]] += 1.0;
}

void AdjacencyList::addEdge(string from, string to) {
    // Add both vertices if needed then add the edge
    addVertexIfNeeded(from);
    addVertexIfNeeded(to);

    edges[from].push_back(to);
    updateOutdegree(from);
}

void AdjacencyList::initializePageRanks() {
    for (int i = 0; i < numVertices; i++) {
        pageRanks[i] = 1.0 / numVertices;
    }
}

void AdjacencyList::PageRank(int n) {
    initializePageRanks();
    // run the algorithm n times
    for (int iteration = 1; iteration < n; iteration++) {
        calculatePageRankIteration();
        updatePageRanks();
        resetSums();
    }

    printPageRanks();
}

void AdjacencyList::calculatePageRankIteration() {
    // calculate pagerank for each vertex
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        int fromIndex = vertexIndex[it->first];
        //iterate through all "to" vertices the "from" vertex points to
        for (size_t i = 0; i < it->second.size(); i++) {
            string to = it->second[i];
            int toIndex = vertexIndex[to];
            // pagerank of the from vertex divided by it's outdegree
            double insert = (1.0 / outdegrees[fromIndex]) * pageRanks[fromIndex];
            sums[toIndex] += insert;
        }
    }
}

void AdjacencyList::updatePageRanks() {
    // updates pageranks for next iteration
    for (int i = 0; i < numVertices; i++) {
        pageRanks[i] = sums[i];
    }
}

void AdjacencyList::resetSums() {
    // sets sums to zero for next iteration
    for (int i = 0; i < numVertices; i++) {
        sums[i] = 0.0;
    }
}

void AdjacencyList::printPageRanks() {
    //sorts and prints page ranks
    map<string, double> sortedPageRanks;
    for (auto it = vertexIndex.begin(); it != vertexIndex.end(); ++it) {
        sortedPageRanks[it->first] = pageRanks[it->second];
    }

    for (auto it = sortedPageRanks.begin(); it != sortedPageRanks.end(); ++it) {
        cout << it->first << " " << fixed << setprecision(2) << it->second << endl;
    }
}

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    AdjacencyList graph;

    cin >> no_of_lines >> power_iterations;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    graph.PageRank(power_iterations);

    return 0;
}
