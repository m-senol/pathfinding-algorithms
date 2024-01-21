#include "Navigator.hpp"

Navigator::Navigator(PathFindingStrategy *strat, std::string path)
: maze(path)
, strategy(strat)
{
}

void Navigator::solve()
{
	strategy->execute(maze);
}

std::vector<Coordinates> Navigator::getSolution() const
{
	return strategy->answer;
}
