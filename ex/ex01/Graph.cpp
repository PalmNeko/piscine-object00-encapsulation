#include <limits>
#include <map>
#include <set>
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
        os << "[" << clampInt(it->x()) << "," << clampInt(it->y()) << "]";
        it++;
    }
    os << std::endl;
}

void Graph::plotConsole(std::ostream &os) const
{
    std::map<int, std::set<int> > field;

    points_t::const_iterator it = points.begin();
    points_t::const_iterator ite = points.end();

    if (it == ite)
        return;
    int x_min = std::numeric_limits<int>::max();
    int y_min = std::numeric_limits<int>::max();
    int x_max = std::numeric_limits<int>::min();
    int y_max = std::numeric_limits<int>::min();

    // make field
    do
    {
        const int x = clampInt(it->x());
        const int y = clampInt(it->y());

        x_min = std::min(x_min, x);
        y_min = std::min(y_min, y);
        x_max = std::max(x_max, x);
        y_max = std::max(y_max, y);
        field[y].insert(x);
    } while (++it != ite);

    if (y_max < std::numeric_limits<int>::max())
        y_max += 1;
    if (x_max < std::numeric_limits<int>::max())
        x_max += 1;

    int x_digit_max = std::max(calcDigit(x_min), calcDigit(x_max)) + 1;
    int y_digit_max = std::max(calcDigit(y_min), calcDigit(y_max)) + 1;

    std::map<int, std::set<int> >::reverse_iterator y_rit = field.rbegin();
    std::map<int, std::set<int> >::reverse_iterator y_rite = field.rend();
    std::set<int>::iterator x_rit = y_rit->second.end();
    std::set<int>::iterator x_rite = y_rit->second.end();

    int y = y_max;
    while (true)
    {
        os << ">&" << std::setw(y_digit_max) << y;
        if (y_rit != y_rite && y_rit->first == y)
        {
            x_rit = y_rit->second.begin();
            x_rite = y_rit->second.end();
            y_rit++;
        }
        int x = x_min;
        while (true)
        {
            if (x_rit != x_rite && *x_rit == x)
            {
                os << std::setw(x_digit_max) << "X";
                x_rit++;
            }
            else
            {
                os << std::setw(x_digit_max) << ".";
            }
            if (x >= x_max)
                break;
            x++;
        }
        os << "\n";
        if (y <= y_min)
            break;
        y--;
    }
    os << ">&" << std::setw(y_digit_max) << " ";
    int x = x_min;
    while (true)
    {
        os << std::setw(x_digit_max) << x;
        if (x >= x_max)
            break;
        x++;
    }
    os << std::endl;
    return;
}
