cmake_minimum_required(VERSION 3.20)
project(esercitazione9) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")


find_package(Eigen3 REQUIRED)

#test
add_executable(test_coniugato test.cpp)
target_link_libraries(test_coniugato Eigen3::Eigen)
add_test(NAME test_coniugato COMMAND test_coniugato)

enable_testing()