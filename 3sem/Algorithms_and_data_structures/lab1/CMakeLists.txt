cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp headers/data.h headers/listOfInts.h )

add_subdirectory(Google_tests)