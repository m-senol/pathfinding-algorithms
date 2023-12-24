#ifndef __DEPTH_FIRST_H__
#define __DEPTH_FIRST_H__

#include <stack>
#include "PathFindingStrategy.h"
#include "UninformedSearch.h"
#include "Coordinates.h"

class DepthFirst : public PathFindingStrategy, public UninformedSearch<std::stack<Coordinates>>
{
    public:
        DepthFirst(Coordinates start, Coordinates finish);
};

#endif