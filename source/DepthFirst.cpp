#include "DepthFirst.hpp"

DepthFirst::DepthFirst()
: UninformedSearch<std::stack<Coordinates>>()
{
}

void DepthFirst::add(const Coordinates& coordinates)
{
	frontier.push(coordinates);
}

Coordinates DepthFirst::remove()
{
	Coordinates c = frontier.top();
	frontier.pop();
	return c;
}

bool DepthFirst::empty()
{
	return frontier.empty();
}
