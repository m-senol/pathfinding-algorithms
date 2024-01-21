#ifndef __MAZE_HPP__
#define __MAZE_HPP__

#define PATH   0
#define WALL   1
#define START  2
#define FINISH 3
#define NUMBER_OF_SYMBOLS 4

#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Coordinates.hpp"

class Maze
{
    public:
        int getRowCount() const;
        int getColumnCount() const;
        int getCellCount() const;
        Coordinates getStart() const;
        Coordinates getFinish() const;

        Maze(std::string path);

        int* operator[](int row);
        const int* operator[](int row) const;
        int operator[](Coordinates coordinates);
        const int operator[](Coordinates coordinates) const;
        friend std::ostream& operator<<(std::ostream& os, const Maze& obj);
    
    private:
        int rowCount;
        int columnCount;
        std::unique_ptr<std::unique_ptr<int[]>[]> maze;
        void import(std::string path);
        Coordinates start;
        Coordinates finish;
};

#endif
