cmake_minimum_required(VERSION 3.12)
project(lab10 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab10
        mergesort.c
        quicksort.c
        quicksort.h
        sorting1498868.c
        sorting1498868.h
        heapsort.c
        bubblesort.c
        selectionsort.c
        insertionsort.c)
