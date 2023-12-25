#include "UninformedSearch.h"

template <class T>
UninformedSearch<T>::UninformedSearch(Coordinates start, Coordinates finish)
: currentPosition(start)
, finish(finish)
{
}

template <class T>
void UninformedSearch<T>::solve()
{
    add(start);
    visited[start] = 0;

    Coordinates currentPosition = start;
    while(True)
    {
        currentPosition = remove();

        if(currentPosition == finish)
        {
            std::cout << "Success!" << std::endl;
            break;
        }

        std::vector<Coordinates> possibleMoves = neighbours(currentPosition);

        for(const Coordinates& c : possibleMoves)
        {
            if(visited.find(c) == visited.end())
            {
                visited[c] = visited[currenntPosition] + 1;
                add(c);
            }
            else
            {
                visited[c] = std::min(visited[c], visited[currenntPosition] + 1;);
            }
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
        Coordinates lastAddition = lastStep(lastAddition);
        answer.push_back(lastAddition);
    }
    std::reverse(answer.begin(), answer.end());
    return;
}

template <class T>
std::vector<Coordinates> UninformedSearch<T>::neighbours(Coordinates currentPosition) const
{
    return std::vector<Coordinates>();
}

template <class T>
Coordinates UninformedSearch<T>::lastStep(Coordinates currentPosition) const
{
    return Coordinates();
}
