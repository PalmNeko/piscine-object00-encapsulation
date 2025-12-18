#include <iostream>
#include <limits>
#include "GraphReader.hpp"
#include "Vector2.hpp"
#include "Graph.hpp"

void plotBasicGraph();
void plotGraphFromFile(const std::string &file);

const int int_max = std::numeric_limits<int>::max();
const int int_min = std::numeric_limits<int>::min();

int main(int, char *argv[])
{
    plotBasicGraph();
    std::cout << std::endl;
    argv++;
    while (*argv != 0)
    {
        plotGraphFromFile(*argv);
        std::cout << std::endl;
        argv++;
    }
    return 0;
}

void plotBasicGraph()
{
    std::cout << "サンプル グラフ" << std::endl;
    Graph graph(Vector2(10, 10));

    graph.addPoint(Vector2(0, 0));
    graph.addPoint(Vector2(2, 2));
    graph.addPoint(Vector2(4, 2.2));
    graph.addPoint(Vector2(2, 4));
    graph.plotConsole(std::cout);
    std::cout << std::endl;
    graph.print(std::cout);
    std::cout << graph.getPoint(Vector2(2, 4)) << std::endl;
}

void plotGraphFromFile(const std::string &file)
{
    Graph graph(Vector2(10, 10));

    try
    {
        GraphReader::read(graph, file);
        graph.plotConsole(std::cout);
        graph.print(std::cout);
    }
    catch (const std::exception &e)
    {
        std::cerr << "plotGraphFromFile: " << e.what() << std::endl;
    }
}
