#ifndef __NAVIGATOR_H__
#define __NAVIGATOR_H__

#include "PathFindingStrategy.h"
#include "Maze.h"

class Navigator
{
    private:
        PathFindingStrategy *strategy;
        Maze maze;

    public:
        Navigator(PathFindingStrategy strategy);
        void solve();
};

#endif
