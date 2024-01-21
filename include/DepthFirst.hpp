#ifndef __DEPTH_FIRST_H__
#define __DEPTH_FIRST_H__

#include <stack>
#include "UninformedSearch.hpp"
#include "Coordinates.hpp"

class DepthFirst : public UninformedSearch<std::stack<Coordinates>>
{
    public:
        DepthFirst();

    private:
        void add(const Coordinates& coordinates) override;
        Coordinates remove() override;
        bool empty() override;
};

#endif
