#include "Coordinates.h"

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
