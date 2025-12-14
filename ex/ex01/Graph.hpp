
#pragma once

#include <vector>
#include <ostream>

#include "Vector2.hpp"

namespace Tookuyam
{
    class Graph
    {
        std::vector<Vector2> points;

    public:
        Graph();
        Graph(const Graph &other);
        ~Graph();

        Graph &operator=(const Graph &other);
        void addPoint(const Vector2 &vec);
        void print(std::ostream &os) const;
        void plotConsole(std::ostream &os) const;
    };
}
