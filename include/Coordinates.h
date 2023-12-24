#ifndef __COORDINATES_H__
#define __COORDINATES_H__

class Coordinates
{
    public:
        int row;
        int column;

        Coordinates();
        Coordinates(int row, int column);

        bool operator==(const Coordinates& other) const;
        bool operator!=(const Coordinates& other) const;
        Coordinates& operator=(const Coordinates& other);
};

#endif
