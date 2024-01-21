#ifndef __COORDINATES_HPP__
#define __COORDINATES_HPP__

#include <iostream>
#include <cmath>

class Coordinates
{
public:
    int row;
    int column;

    Coordinates();
    Coordinates(int row, int column);

    static std::size_t hash(const Coordinates& p);
    
    double distance(const Coordinates& other) const;

    bool operator==(const Coordinates& other) const;
    bool operator!=(const Coordinates& other) const;
    Coordinates& operator=(const Coordinates& other);
    friend std::ostream& operator<<(std::ostream& os, const Coordinates& obj);

};

#endif
