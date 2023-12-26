#ifndef __UNINFORMED_SEARCH_H__
#define __UNINFORMED_SEARCH_H__

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Coordinates.h"
#include "PathFindingStrategy.h"

template <class T>
class UninformedSearch : public PathFindingStrategy
{
    private:
        std::unordered_map<Coordinates> visited;

        int start;
        int finish;

    protected:
        T frontier;
        
        UninformedSearch(Coordinates start, Coordinates finish);
        std::vector<Coordinates> neighbours(Coordinates currentPosition) const;
        Coordinates lastStep(Coordinates currentposition) const;
        void solve();
        
        virtual void add(const Coordinates& coordinates) = 0;
        virtual Coordinates remove() = 0;
        virtual bool empty() = 0;
    
    public:
        std::vector<Coordinates> answer;
        
};

#endif
