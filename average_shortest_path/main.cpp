#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "graph.hpp"
using namespace std;

float shortest_path(Graph g, int target);

int main(int argc, char** argv) {
    srand(time(nullptr));

    Graph a = Graph(5, 0.5, 1, 10);
    cout << fixed << a << endl;
    shortest_path(a, 3);
    // cout << shortest_path(a, 3);

    return 0;
}

float shortest_path(Graph g, int target) {
    float* path_length = new float(g.node);
    for (int i = 1; i < g.node; i++) path_length[i] = -1;

    // int node_to_expand;

    // do {
    //     // expand one node
    //     node_to_expand = 0;
    //     float current_length = numeric_limits<float>::infinity();

    //     for (int i = 0; i < g.node; i++) {
    //         if (!path_length[i] < 0) {  // i is nodes in closed set
    //             for (int j = 0; j < g.node; j++) {
    //                 if (path_length[j] < 0 &&
    //                     g.g[i][j] > 0) {  // j is nodes not in closed set and
    //                                       // can be reached from i
    //                     if (g.g[i][j] + path_length[i] < current_length) {
    //                         current_length = g.g[i][j] + path_length[i];
    //                         node_to_expand = j;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // } while (node_to_expand != 0);

    float result = path_length[target];
    // delete[] path_length;
    return result;
}
