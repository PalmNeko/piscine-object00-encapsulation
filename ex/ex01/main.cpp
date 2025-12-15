#include <iostream>
#include <limits>
#include "Vector2.hpp"
#include "Graph.hpp"

void plotBasicGraph();

const int int_max = std::numeric_limits<int>::max();
const int int_min = std::numeric_limits<int>::min();

int main()
{
    plotBasicGraph();
    std::cout << std::endl;
    return 0;
}

void plotBasicGraph()
{
    std::cout << "サンプル グラフ" << std::endl;
    Graph graph(5, 5);

    graph.addPoint(Vector2(0, 0));
    graph.addPoint(Vector2(2, 2));
    graph.addPoint(Vector2(4, 2));
    graph.addPoint(Vector2(2, 4));
    graph.plotConsole(std::cout);
}
