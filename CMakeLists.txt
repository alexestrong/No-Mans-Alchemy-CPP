cmake_minimum_required(VERSION 3.17)
project(project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(project2 proj2.cpp Game.h Material.h Ship.h Ship.cpp Game.cpp)