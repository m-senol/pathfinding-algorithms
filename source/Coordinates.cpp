#include "Coordinates.hpp"

Coordinates::Coordinates()
: row(0)
, column(0)
{
}

Coordinates::Coordinates(int row, int column)
: row(row)
, column(column)
{
}

std::size_t Coordinates::hash(const Coordinates& c)
{
    return std::hash<int>()(c.row) ^ (std::hash<int>()(c.column) << 1);
}

double Coordinates::distance(const Coordinates& other) const
{
    return sqrt(pow(row-other.row, 2)+pow(column-other.column, 2));
}

bool Coordinates::operator==(const Coordinates& other) const
{
    return (row == other.row) && (column == other.column);
}

bool Coordinates::operator!=(const Coordinates& other) const
{
    return !((*this) == other);
}

Coordinates& Coordinates::operator=(const Coordinates& other)
{
    if(this != &other)
    {
        row = other.row;
        column = other.column;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Coordinates& obj)
{
    os << "(" << obj.row << ", " << obj.column << ")";
    return os;
}
