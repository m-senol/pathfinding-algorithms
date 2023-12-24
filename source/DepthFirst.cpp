#include "DepthFirst.h"

DepthFirst::DepthFirst(Coordinates start, Coordinates finish)
: UninformedSearch<std::stack<Coordinates>>(start, finish)
{
}
