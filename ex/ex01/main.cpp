#include <iostream>
#include <limits>
#include "Vector2.hpp"
#include "Graph.hpp"

void plotBasicGraph();
void plotBasicGraph2();
void plotFirstQuadrantGraph();
void plotSecondQuadrantGraph();
void plotThirdQuadrantGraph();
void plotForthQuadrantGraph();

const int int_max = std::numeric_limits<int>::max();
const int int_min = std::numeric_limits<int>::min();

int main()
{
    plotBasicGraph();
    std::cout << std::endl;
    plotBasicGraph2();
    std::cout << std::endl;

    // 極端に大きい値は、float型で保存すると少し足したぐらいでは差が生まれなくなってしまう。
    plotFirstQuadrantGraph();
    std::cout << std::endl;
    plotSecondQuadrantGraph();
    std::cout << std::endl;
    plotThirdQuadrantGraph();
    std::cout << std::endl;
    plotForthQuadrantGraph();
    std::cout << std::endl;
    return 0;
}

void plotBasicGraph()
{
    std::cout << "サンプル グラフ" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(0, 0));
    graph.addPoint(Tookuyam::Vector2(2, 2));
    graph.addPoint(Tookuyam::Vector2(4, 2));
    graph.addPoint(Tookuyam::Vector2(2, 4));
    graph.plotConsole(std::cout);
}

void plotBasicGraph2()
{
    std::cout << "サンプル グラフ2" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(3, 3));
    graph.addPoint(Tookuyam::Vector2(3, -3));
    graph.addPoint(Tookuyam::Vector2(-3, 3));
    graph.addPoint(Tookuyam::Vector2(-3, -3));
    graph.plotConsole(std::cout);
}

void plotFirstQuadrantGraph()
{
    std::cout << "第一象限 グラフ" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(int_max, int_max));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_max, 3.0f + int_max));
    graph.addPoint(Tookuyam::Vector2(-3.0f + int_max, -3.0f + int_max));
    graph.addPoint(Tookuyam::Vector2(-3.0f + int_max, int_max));
    graph.addPoint(Tookuyam::Vector2(int_max, -3.0f + int_max));
    graph.plotConsole(std::cout);
}

void plotSecondQuadrantGraph()
{
    std::cout << "第二象限 グラフ" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(int_min, int_max));
    graph.addPoint(Tookuyam::Vector2(-3.0f + int_min, 3.0f + int_max));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_min, -3.0f + int_max));
    graph.addPoint(Tookuyam::Vector2(int_min, -3.0f + int_max));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_min, int_max));
    graph.plotConsole(std::cout);
}

void plotThirdQuadrantGraph()
{
    std::cout << "第三象限 グラフ" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(int_min, int_min));
    graph.addPoint(Tookuyam::Vector2(-3.0f + int_min, -3.0f + int_min));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_min, 3.0f + int_min));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_min, int_min));
    graph.addPoint(Tookuyam::Vector2(int_min, 3.0f + int_min));
    graph.plotConsole(std::cout);
}

void plotForthQuadrantGraph()
{
    std::cout << "第四象限 グラフ" << std::endl;
    Tookuyam::Graph graph;

    graph.addPoint(Tookuyam::Vector2(int_max, int_min));
    graph.addPoint(Tookuyam::Vector2(3.0f + int_max, -3.0f + int_min));
    graph.addPoint(Tookuyam::Vector2(int_max - 3.0f, int_min + 3.0f));
    graph.addPoint(Tookuyam::Vector2(int_max, int_min + 3.0f));
    graph.addPoint(Tookuyam::Vector2(int_max - 3.0f, int_min));
    // graph.print(std::cout);
    graph.plotConsole(std::cout);
}
