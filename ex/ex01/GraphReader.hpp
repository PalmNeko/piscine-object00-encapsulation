#pragma once

#include <string>
#include "Graph.hpp"

class GraphReader
{
    typedef GraphReader Class;

    GraphReader() {};
    GraphReader(Class &) {};
    ~GraphReader() {};
    Class &operator=(Class &) { return *this; };

public:
    static void read(Graph &graph, const std::string &file);
    static void read(Graph &graph, std::istream &is);
};
