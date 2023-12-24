#ifndef __NAVIGATOR_H__
#define __NAVIGATOR_H__

#include "PathFindingStrategy.h"

class Navigator
{
    private:
        PathFindingStrategy *strategy;

    public:
        Navigator(PathFindingStrategy strategy);
        void solve();
};

#endif
