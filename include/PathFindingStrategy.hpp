#ifndef __PATH_FINDING_STRATEGY_HPP__
#define __PATH_FINDING_STRATEGY_HPP__

#include <vector>
#include "Maze.hpp"
#include "Coordinates.hpp"

class PathFindingStrategy {
    public:
        virtual void execute(const Maze& maze) = 0;
        std::vector<Coordinates> answer;

    protected:
        PathFindingStrategy();
};

#endif
