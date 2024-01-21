#include "UninformedSearch.hpp"

template <class T>
UninformedSearch<T>::UninformedSearch()
: PathFindingStrategy()
, visited(1024, &Coordinates::hash)
{
}

template <class T>
void UninformedSearch<T>::execute(const Maze& maze)
{
    Coordinates start = maze.getStart();
    Coordinates finish = maze.getFinish();
    
    add(start);
    visited[start] = 0;
    Coordinates currentPosition = start;
    while(true)
    {
        currentPosition = remove();

        if(currentPosition == finish)
        {
            std::cout << "Success!" << std::endl;
            break;
        }

        std::vector<Coordinates> possibleMoves = neighbours(maze, currentPosition);

        for(const Coordinates& c : possibleMoves)
        {
            visited[c] = visited[currentPosition] + 1;
            add(c);
        }
        
        if (empty())
        {
            std::cout << "Fail!" << std::endl;
            return;
        }
    }

    answer.push_back(finish);
    Coordinates lastAddition = finish;
    while(lastAddition != start)
    {
        lastAddition = lastStep(maze, lastAddition);
        answer.push_back(lastAddition);
    }
    std::reverse(answer.begin(), answer.end());
    return;
}

template<class T>
bool UninformedSearch<T>::isVisited(const Coordinates coord) const
{
    auto it = visited.find(coord);

    if (it != visited.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
std::vector<Coordinates> UninformedSearch<T>::neighbours(const Maze& maze, const Coordinates coords) const
{
    int sr = std::max(0, coords.row - 1);
    int br = std::min(maze.getRowCount() - 1, coords.row + 1);
    int sc = std::max(0, coords.column - 1);
    int bc = std::min(maze.getColumnCount() - 1, coords.column + 1);
    std::vector<Coordinates> c;
    for (int i = sr; i <= br; ++i)
    {
        for (int j = sc; j <= bc; ++j)
        {
            Coordinates candidate(i, j);
            if (coords == candidate || maze[candidate] == WALL || isVisited(candidate) || coords.distance(candidate) > 1)
            {
                continue;
            }
            else
            {
                c.push_back(candidate);
            }
        }
    }
    return c;
}

template <class T>
Coordinates UninformedSearch<T>::lastStep(const Maze& maze, const Coordinates coords) const
{
    std::vector<Coordinates> candidates;
    

    int sr = std::max(0, coords.row - 1);
    int br = std::min(maze.getRowCount() - 1, coords.row + 1);
    int sc = std::max(0, coords.column - 1);
    int bc = std::min(maze.getColumnCount() - 1, coords.column + 1);

    for (int i = sr; i <= br; ++i)
    {
        for (int j = sc; j <= bc; ++j)
        {
            Coordinates candidate(i, j);
            if (coords == candidate || maze[candidate] == WALL || !isVisited(candidate) || candidate.distance(coords) > 1)
            {
                continue;
            }
            else
            {
                candidates.push_back(candidate);
            }
        }
    }

    Coordinates c = candidates.front();
    int minimum = visited.find(c)->second;
    
    for (auto i = candidates.begin() + 1; i < candidates.end(); ++i)
    {
        int current = visited.at(*i);

        if (current < minimum)
        {
            c = *i;
            minimum = current;
        }
    }
    return c;
    
}

template class UninformedSearch<std::queue<Coordinates>>;
template class UninformedSearch<std::stack<Coordinates>>;
