cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp headers/queue/queue.h headers/queue/elemOfQueue.h headers/stack/stack.h headers/stack/elemOfStack.h headers/iterator/iterator.h headers/binaryTreeSearch/binaryTreeSearch.h headers/binaryTreeSearch/elemOfBinaryTreeSearch.h)
add_subdirectory(Google_tests)