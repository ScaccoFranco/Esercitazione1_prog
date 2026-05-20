cmake_minimum_required(VERSION 3.20)
project(esercitazione9) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

## mio eseguibile principale in cui misuro i tempip dei sorting
set(SRC_es9 main.cpp header.hpp)
add_executable(esercitazione9 ${SRC_es9})
