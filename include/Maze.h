#ifndef __MAZE_H__
#define __MAZE_H__

#define PATH   0
#define WALL   1
#define START  2
#define FINISH 3

#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

class Maze
{
    private:
        int rowCount;
        int columnCount;
        std::unique_ptr<std::unique_ptr<int[]>[]> maze;

    public:
        Maze();
        void import(std::string path);
};

#endif
