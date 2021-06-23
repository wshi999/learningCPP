#include <cstdlib>
#include <ctime>
#include <iostream>

#include "graph.hpp"
using namespace std;

int main(int argc, char** argv) {
    srand(time(nullptr));

    Graph a = Graph(50, 0.5, 1, 40);
    cout << fixed;
    // cout << a << endl;
    return 0;
}
