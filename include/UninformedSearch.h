#ifndef __UNINFORMED_SEARCH_H__
#define __UNINFORMED_SEARCH_H__

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Coordinates.h"

template <class T>
class UninformedSearch
{
    private:
        std::unordered_map<Coordinates> visited;

        int start;
        int finish;

    protected:
        T frontier;
        
        UninformedSearch(Coordinates start, Coordinates finish);
        std::vector<Coordinates> neighbours(Coordinate currentPosition);
        void solve();
        
        
        virtual bool exist(const Coordinates& coordinates) = 0;
        virtual void add(const Coordinates& coordinates) = 0;
        virtual Coordinates remove() = 0;
        virtual bool empty() = 0;
        
};

#endif
