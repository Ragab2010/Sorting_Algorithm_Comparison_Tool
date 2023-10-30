cmake_minimum_required(VERSION 3.0)

project(SortAlgorithmCompTool)

# Set C++ standard (Change to your desired standard)
set(CMAKE_CXX_STANDARD 17)

# Add your source files
file(GLOB SOURCES src/*.cpp)

# Include directories
include_directories(include)

# Add executable target
add_executable(SortAlgorithmCompTool ${SOURCES})


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)