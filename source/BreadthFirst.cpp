#include "BreadthFirst.hpp"

BreadthFirst::BreadthFirst()
: UninformedSearch<std::queue<Coordinates>>()
{
}

void BreadthFirst::add(const Coordinates& coordinates)
{
	frontier.push(coordinates);
}

Coordinates BreadthFirst::remove()
{
	Coordinates c = frontier.front();
	frontier.pop();
	return c;
}

bool BreadthFirst::empty()
{
	return frontier.empty();
}
