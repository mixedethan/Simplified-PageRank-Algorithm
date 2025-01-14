#include "AdjacencyList.h"

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
    // increment outdegree count for the "from" vertex
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
        // iterate through all "to" vertices the "from" vertex points to
        for (size_t i = 0; i < it->second.size(); i++) {
            string to = it->second[i];
            int toIndex = vertexIndex[to];
            // pagerank of the from vertex divided by its outdegree
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
    // sorts and prints page ranks
    map<string, double> sortedPageRanks;
    for (auto it = vertexIndex.begin(); it != vertexIndex.end(); ++it) {
        sortedPageRanks[it->first] = pageRanks[it->second];
    }

    for (auto it = sortedPageRanks.begin(); it != sortedPageRanks.end(); ++it) {
        cout << it->first << " " << fixed << setprecision(2) << it->second << endl;
    }
}
