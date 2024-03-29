#ifndef __BREADTH_FIRST_HPP__
#define __BREADTH_FIRST_HPP__

#include <queue>
#include "UninformedSearch.hpp"
#include "Coordinates.hpp"


class BreadthFirst : public UninformedSearch<std::queue<Coordinates>>
{
    public:
        BreadthFirst();

    private:
        void add(const Coordinates& coordinates) override;
        Coordinates remove() override;
        bool empty() override;
};

#endif
