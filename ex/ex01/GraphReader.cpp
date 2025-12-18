#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include "GraphReader.hpp"

static std::vector<std::string> split(const std::string &str, char delim = ',')
{
    std::istringstream iss(str);
    std::string part;
    std::vector<std::string> strings;

    if (str.empty())
        return strings;

    while (std::getline(iss, part, delim))
        strings.push_back(part);
    return strings;
}

static float parseFloat(const std::string &str)
{
    float ret;
    std::istringstream iss(str);

    iss >> ret;
    if (iss.fail() || iss.eof() == false)
        return NAN;
    return ret;
}

static std::string trim(const std::string &str, const std::string &ignore_set = " \t\n\v\f")
{
    const std::size_t start_pos = str.find_first_not_of(ignore_set);
    std::size_t end_pos = str.find_last_not_of(ignore_set);
    if (end_pos != std::string::npos)
        end_pos += 1;
    return str.substr(start_pos, end_pos);
}

void GraphReader::read(Graph &graph, const std::string &file)
{
    std::ifstream ifs;

    ifs.open(file.c_str());
    if (ifs.bad())
        return;
    read(graph, ifs);
}

void GraphReader::read(Graph &graph, std::istream &is)
{
    std::string line;
    std::vector<std::string> args;

    while (std::getline(is, line))
    {
        args = split(line);
        if (args.size() != 2)
            continue;
        float x = parseFloat(trim(args[0]));
        float y = parseFloat(trim(args[1]));
        if (isfinite(x) == false || isfinite(y) == false)
            continue;
        graph.addPoint(Vector2(x, y));
    }
}
