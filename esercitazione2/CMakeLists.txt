cmake_minimum_required(VERSION 3.20)

project(esercitazione2)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(esempio esempio.cpp)
add_executable(algoritmo algoritmo.cpp)

