#ifndef __BREADTH_FIRST_H__
#define __BREADTH_FIRST_H__

#include <queue>
#include "PathFindingStrategy.h"
#include "UninformedSearch.h"

class BreadthFirst : public PathFindingStrategy, public UninformedSearch<std::queue<Coordinates>>
{
    public:
        BreadthFirst(Coordinates start, Coordinates finish);
};

#endif
