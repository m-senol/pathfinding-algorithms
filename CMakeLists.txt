cmake_minimum_required (VERSION 3.8)

project ("pathfinding")

# List source files
set(SOURCES
    source/Coordinates.cpp
    source/Maze.cpp
    source/PathFindingStrategy.cpp
    source/BreadthFirst.cpp
    source/DepthFirst.cpp
    source/Navigator.cpp
    main.cpp
)

# List header files
set(HEADERS
    include/Coordinates.hpp
    include/Maze.hpp
    include/PathFindingStrategy.hpp
    include/UninformedSearch.hpp
    include/UninformedSearch.tpp
    include/BreadthFirst.hpp
    include/DepthFirst.hpp
    include/Navigator.hpp
)

add_executable (pathfinding ${SOURCES})

target_include_directories(pathfinding PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pathfinding PROPERTY CXX_STANDARD 20)
endif()
