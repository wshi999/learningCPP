#include <cstdlib>
#include <ctime>
#include <iostream>

class Graph {
   private:
    /* data */
    const float density, min_distance, max_distance;
    float _gen_value();

   public:
    const int node;
    float** g;
    Graph(int node, float density, float min_distance, float max_distance);
    ~Graph();

    friend std::ostream& operator<<(std::ostream& os, const Graph& g);
};
