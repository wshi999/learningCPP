#include "graph.hpp"

using namespace std;

Graph::Graph(int node, float density, float min_distance, float max_distance)
    : node(node),
      density(density),
      min_distance(min_distance),
      max_distance(max_distance) {
    // allocate memory
    for (int i = 0; i < node; i++) {
        g[i] = new float(node);
    }

    // generate value
    for (int i = 0; i < node; i++) {
        g[i][i] = 0;
        for (int j = i + 1; j < node; j++) {
            g[i][j] = g[j][i] = _gen_value();
        }
    }
}
Graph::~Graph() {}

ostream& operator<<(ostream& os, const Graph& g) {
    for (int i = 0; i < g.node; i++) {
        for (int j = 0; j < g.node; j++) os << g.g[i][j] << "\t, ";
        os << endl;
    }
    return os;
}

float Graph::_gen_value() {
    if (rand() > density * RAND_MAX) return -1;
    return min_distance + (max_distance - min_distance) *
                              (static_cast<float>(rand()) / RAND_MAX);
}
