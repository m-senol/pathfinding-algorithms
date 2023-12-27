#include "Maze.h"

Maze::Maze()
: rowCount(0)
, columnCount(0)
, maze(nullptr)
{
}

void Maze::import(std::string path)
{
    std::stringstream fileContents;
    std::ifstream file(path);
    if (!file.is_open())
    {
        // Error Message
        // Exception
        return;
    }
    fileContents << file.rdbuf(); 
    file.close();

    fileContents >> rowCount >> columnCount;

    std::unordered_map<std::string, char> legend;
    std::string symbolName;
    char symbolChar;
    while (fileContents >> symbolName >> symbolChar)
    {
        legend[symbolName] = symbolChar;
    }

    auto maze = std::make_unique<std::unique_ptr<int[]>[]>(rowCount);
    std::string line;
    std::getline(fileContents, line);
    for (int i = 0; i < rowCount; ++i)
    {
        std::getline(fileContents, line);
        maze[i] = std::make_unique<int[]>(columnCount);
        for (int j = 0; j < columnCount; ++j)
        {
            
        }
    }
}
