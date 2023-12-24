#include "BreadthFirst.h"

BreadthFirst::BreadthFirst(Coordinates start, Coordinates finish)
: UninformedSearch<std::queue<Coordinates>>(start, finish)
{
}
