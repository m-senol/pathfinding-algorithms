#ifndef __UNINFORMED_SEARCH_H__
#define __UNINFORMED_SEARCH_H__

#include <unordered_set>
#include "Coordinates.h"

template <class T>
class UninformedSearch
{
    private:
        T frontier;
        std::unordered_set<Coordinates> visited;

    protected:
        UninformedSearch(Coordinates start, Coordinates finish);

    public:
        void solve();
};

#endif
