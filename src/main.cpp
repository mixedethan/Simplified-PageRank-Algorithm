/*
 *      Simplified PageRank Algorithm
 *            by Ethan Wilson
 *
 */

/*
 *
 *  TODO: Add damping factor or normalization
 *
 */

#include <iostream>
#include <string>
#include "AdjacencyList.h"
using namespace std;



int main() {
    int no_of_lines, power_iterations;
    cout << "Welcome to the Simple PageRank Algorithm!\n";
    cout << "How many edges will you provide? ";
    cin >> no_of_lines;

    cout << "How many iterations of PageRank would you like to run? ";
    cin >> power_iterations;

    AdjacencyList graph;

    cout << "Please enter " << no_of_lines << " edges in the format: FROM TO\n\n";
    for (int i = 0; i < no_of_lines; i++) {
        string from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    graph.PageRank(power_iterations);

    return 0;
}
