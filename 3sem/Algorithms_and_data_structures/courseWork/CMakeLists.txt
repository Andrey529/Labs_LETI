cmake_minimum_required(VERSION 3.17)
project(courseWork)

set(CMAKE_CXX_STANDARD 20)

add_executable(courseWork main.cpp headers/stack/stack.h src/stack/stack.cpp headers/stack/elemOfStack.h src/stack/elemOfStack.cpp headers/functions/functions.h src/functions/functions.cpp)
add_subdirectory(Google_tests)