cmake_minimum_required(VERSION 2.8)

project(algolearn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

set(link_lib pthread)

add_executable(algolearn main.cpp)

target_link_libraries(algolearn ${link_lib})
