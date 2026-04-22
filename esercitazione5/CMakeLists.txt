cmake_minimum_required(VERSION 3.20)
project(esercitazione4) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

## mio eseguibile principale in cui misuro i tempip dei sorting
set(SRC_test_sorts timecounter.cpp measure_sorts.cpp)
add_executable(measure_sorts ${SRC_test_sorts})

## confronto dimensioni da 1 a 100 per trovare punto di incontro per diversi tipi di ordinamento
set(SRC_test_sorts timecounter.cpp confronto.cpp)
add_executable(confronto ${SRC_test_sorts})


## test dei sorting
add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

enable_testing()