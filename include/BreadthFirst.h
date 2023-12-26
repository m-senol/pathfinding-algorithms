#ifndef __BREADTH_FIRST_H__
#define __BREADTH_FIRST_H__

#include <queue>
#include "UninformedSearch.h"
#include "Coordinates.h"

class BreadthFirst : public UninformedSearch<std::queue<Coordinates>>
{
    public:
        BreadthFirst(Coordinates start, Coordinates finish);
};

#endif
