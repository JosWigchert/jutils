cmake_minimum_required(VERSION 3.0)
project(jutils)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/progress.cpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

