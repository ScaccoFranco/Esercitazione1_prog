cmake_minimum_required(VERSION 3.20)
project(esercitazione4) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

## mio eseguibile principale in cui misuro i tempip dei sorting
set(SRC_test_edges main.cpp unidirected_edge.hpp unidirected_graph.hpp)
add_executable(test_edges ${SRC_test_edges})
