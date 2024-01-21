#include <iostream>
#include "BreadthFirst.hpp"
#include "DepthFirst.hpp"
#include "Navigator.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./pathfinding <path-to-maze-file>\n";
        return 1;
    }
    BreadthFirst* bf = new BreadthFirst();

    Navigator n(bf, argv[1]);
    n.solve();
    
    for (const auto& i : n.getSolution())
    {
        std::cout << i << std::endl;
    }
    
    return 0;
}
