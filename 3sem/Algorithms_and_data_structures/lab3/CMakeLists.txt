cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp headers/queue.h src/queue.cpp src/elemOfQueue.cpp headers/elemOfQueue.h)
add_subdirectory(Google_tests)