#ifndef __UNINFORMED_SEARCH_H__
#define __UNINFORMED_SEARCH_H__

#include "Coordinates.hpp"
#include "Maze.hpp"
#include "PathFindingStrategy.hpp"
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>

template <class T>
class UninformedSearch : public PathFindingStrategy
{
    public:
        void execute(const Maze& maze) override;
    
    protected:
        T frontier;
        
        UninformedSearch();
        std::vector<Coordinates> neighbours(const Maze& maze, const Coordinates currentPosition) const;
        Coordinates lastStep(const Maze& maze, const Coordinates currentposition) const;
        
        virtual void add(const Coordinates& coordinates) = 0;
        virtual Coordinates remove() = 0;
        virtual bool empty() = 0;
    
    private:
        std::unordered_map<Coordinates, int, decltype(&Coordinates::hash)> visited;
        Coordinates currentPosition;

        bool isVisited(const Coordinates coord) const;
};

#include <UninformedSearch.tpp>

#endif
