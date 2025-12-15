#include <limits>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Graph.hpp"

static int clampInt(float a)
{
    if (a <= std::numeric_limits<int>::min())
        return std::numeric_limits<int>::min();
    else if (a >= std::numeric_limits<int>::max())
        return std::numeric_limits<int>::max();
    return (int)a;
}

static int calcDigit(int x)
{
    if (x == std::numeric_limits<int>::min())
        return calcDigit(x + 1);
    int digit = static_cast<int>(std::log10(std::abs(x))) + 1;
    if (x < 0)
        return digit + 1;
    return digit;
}

Graph &Graph::operator=(const Graph &other)
{
    if (this != &other)
    {
        this->points = other.points;
    }
    return *this;
}

void Graph::addPoint(const Vector2 &vec)
{
    if (vec.x() < 0 || vec.x() >= size.x())
        throw std::runtime_error("Over the size");
    if (vec.y() < 0 || vec.y() >= size.y())
        throw std::runtime_error("Over the size");
    points.insert(vec);
}

void Graph::print(std::ostream &os) const
{
    points_t::const_iterator it = points.begin();
    points_t::const_iterator ite = points.end();

    bool comma = false;
    while (it != ite)
    {
        if (comma)
            os << ",";
        comma = true;
        os << "[" << it->x() << "," << it->y() << "]";
        it++;
    }
    os << std::endl;
}

void Graph::plotConsole(std::ostream &os) const
{
    std::vector<std::vector<char> > display(size.y(), std::vector<char>(size.x(), '.'));

    if (display.size() == 0 || display[0].size() == 0)
        return;
    points_t::const_iterator it = points.begin();
    points_t::const_iterator ite = points.end();

    if (it == ite)
        return;
    while (it != ite)
    {
        const int x = clampInt(it->x());
        const int y = clampInt(it->y());
        display[y][x] = 'X';
        it++;
    }

    int x_digit_max = calcDigit(size.x()) + 1;
    int y_digit_max = calcDigit(size.y()) + 1;

    for (size_t yi = display.size(); yi > 0; yi--)
    {
        size_t y = yi - 1;
        os << ">&" << std::setw(y_digit_max) << y;
        for (size_t x = 0; x < display[y].size(); x++)
            os << std::setw(x_digit_max) << display[y][x];
        os << "\n";
    }
    os << ">&" << std::setw(y_digit_max) << " ";
    if (display.size() != 0)
    {
        for (size_t x = 0; x < display[0].size(); x++)
            os << std::setw(x_digit_max) << x;
    }
    os << std::endl;
    return;
}
