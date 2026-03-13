
# versione minima

cmake_minimum_required(VERSION 3.20)

# nome progetto
project(esercitazione1)

# versione cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# chiamata warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(medie_temperature medie_temperature.cpp)

