
#pragma once

#include <set>
#include <ostream>

#include "Vector2.hpp"

class Graph
{
    typedef std::set<Vector2> points_t;
    points_t points;

public:
    Graph() {};
    Graph(const Graph &other) : points(other.points) {};
    ~Graph() {};

    Graph &operator=(const Graph &other);
    void addPoint(const Vector2 &vec);
    void print(std::ostream &os) const;
    void plotConsole(std::ostream &os) const;
};
