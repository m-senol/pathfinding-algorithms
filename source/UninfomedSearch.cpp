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

    std::vector<Coordinates> answer;
    answer.push_back(finish);

    Coordinates lastAddition = finish;
    while(lastAddition != start)
    {
        // TODO: Retrace your steps
    }

    std::reverse(answer.begin(), answer.end());
    return;
}
