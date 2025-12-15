
#pragma once

#include <set>
#include <ostream>

#include "Vector2.hpp"

class Graph
{
    typedef std::set<Vector2> points_t;
    points_t points;
    Vector2 size;

public:
    Graph() : size(Vector2(0, 0)) {};
    Graph(const Vector2 &size) : size(size) {};
    Graph(const Graph &other) : points(other.points) {};
    ~Graph() {};

    Graph &operator=(const Graph &other);
    void addPoint(const Vector2 &vec);
    const Vector2 &getPoint(const Vector2 &vec)
    {
        points_t::const_iterator it = points.find(vec);
        if (it == points.end())
            throw std::runtime_error("can't find");
        return *it;
    }
    void print(std::ostream &os) const;
    void plotConsole(std::ostream &os) const;
};
