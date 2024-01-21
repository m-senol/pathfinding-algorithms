#ifndef __NAVIGATOR_HPP__
#define __NAVIGATOR_HPP__

#include <string>
#include <vector>
#include "PathFindingStrategy.hpp"
#include "Maze.hpp"

class Navigator
{
    private:
        Maze maze;
        PathFindingStrategy *strategy;

    public:
        Navigator(PathFindingStrategy *strat, const std::string path);
        void solve();
        std::vector<Coordinates> getSolution() const;
};

#endif
