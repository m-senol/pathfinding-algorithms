#include "Maze.hpp"

Maze::Maze(std::string path)
{
    import(path);

    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < columnCount; ++j)
        {
            if (maze[i][j] == START)
            {
                start = Coordinates(i, j);
            }
            else if (maze[i][j] == FINISH)
            {
                finish = Coordinates(i, j);
            }
        }
    }
}

int* Maze::operator[](int row)
{
    // test if row in range
    return maze[row].get();
}

const int* Maze::operator[](int row) const
{
    // test if row in range
    return maze[row].get();
}

int Maze::operator[](Coordinates coordinates)
{
    // test if in range
    return maze[coordinates.row][coordinates.column];
}

const int Maze::operator[](Coordinates coordinates) const
{
    // test if in range
    return maze[coordinates.row][coordinates.column];
}

int Maze::getRowCount() const
{
    return rowCount;
}

int Maze::getColumnCount() const
{
    return columnCount;
}

int Maze::getCellCount() const
{
    return rowCount * columnCount;
}

Coordinates Maze::getStart() const
{
    return start;
}

Coordinates Maze::getFinish() const
{
    return finish;
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

    std::unordered_map<char, int> legend;
    int symbolNumber;
    char symbolChar;
    for(int i = 0; i < NUMBER_OF_SYMBOLS; ++i)
    {
        fileContents >> symbolNumber >> symbolChar;
        legend[symbolChar] = symbolNumber;
    }

    maze = std::make_unique<std::unique_ptr<int[]>[]>(rowCount);
    std::string line;
    for (int i = 0; i < rowCount; ++i)
    {
        fileContents >> line;
        maze[i] = std::make_unique<int[]>(columnCount);
        for (int j = 0; j < columnCount; ++j)
        {
            // Exceptions etc.
            char c = line[j];
            maze[i][j] = legend[c];
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Maze& obj)
{
    for (int i = 0; i < obj.rowCount; ++i)
    {
        for (int j = 0; j < obj.columnCount; ++j)
        {
            os << obj[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
