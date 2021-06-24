#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "graph.hpp"
using namespace std;

float shortest_path(Graph& g, int target);
float average_shortest_path(Graph& g);

int main(int argc, char** argv) {
    srand(time(nullptr));

    Graph a(50, 0.4, 1, 10);
    cout << average_shortest_path(a);

    return 0;
}

float shortest_path(Graph& g, int target) {
    float* path_length = new float[g.node];
    for (int i = 1; i < g.node; i++) path_length[i] = -1;

    int node_to_expand;

    while (true) {
        // expand one node
        node_to_expand = 0;
        float current_length = numeric_limits<float>::infinity();

        for (int i = 0; i < g.node; i++) {
            if (path_length[i] >= 0) {  // i is nodes in closed set
                for (int j = 0; j < g.node; j++) {
                    if (path_length[j] < 0 &&
                        g.g[i][j] > 0) {  // j is nodes not in closed set and
                                          // can be reached from i
                        if (g.g[i][j] + path_length[i] < current_length) {
                            current_length = g.g[i][j] + path_length[i];
                            node_to_expand = j;
                        }
                    }
                }
            }
        }
        if (node_to_expand == 0) break;
        path_length[node_to_expand] = current_length;
    }

    float result = path_length[target];
    delete[] path_length;
    return result;
}

float average_shortest_path(Graph& g) {
    int linked_nodes = 0;
    float sum = 0;
    float length;
    for (int i = 1; i < g.node; i++) {
        length = shortest_path(g, i);
        if (length > 0) {
            sum += length;
            linked_nodes++;
        }
    }
    return sum / linked_nodes;
}