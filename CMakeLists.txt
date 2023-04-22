cmake_minimum_required(VERSION 3.25)
project(InstaRecipe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(InstaRecipe
        main.cpp
        QuickSort.cpp
        recipe.cpp
        recipe.h QuickSort.h)
