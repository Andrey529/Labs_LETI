cmake_minimum_required(VERSION 3.17)
project(kurs)

set(CMAKE_CXX_STANDARD 17)

add_executable(kurs main.cpp
        headers/countStamps/elemListOfCountStamps.h
        src/countStamps/elemListOfCountStamps.cpp
        headers/countStamps/listOfCountStamps.h
        src/countStamps/listOfCountStamps.cpp headers/countStamps/situations.h headers/functions/functions.h src/functions/functions.cpp)