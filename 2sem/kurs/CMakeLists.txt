cmake_minimum_required(VERSION 3.17)
project(kurs)

set(CMAKE_CXX_STANDARD 17)

add_executable(kurs main.cpp
        headers/countStamps/elemListOfCountStamps.h
        src/countStamps/elemListOfCountStamps.cpp
        headers/countStamps/listOfCountStamps.h
        src/countStamps/listOfCountStamps.cpp
        headers/situations.h
        headers/functions/functions.h
        src/functions/functions.cpp
        headers/informationAboutLetters/elementOfListLetters.h
        headers/informationAboutLetters/listOfLetters.h
        src/informationAboutLetters/elementOfListLetters.cpp
        src/informationAboutLetters/listOfLetters.cpp
        headers/listOfPartsString/dataOfPartString.h headers/listOfPartsString/partOfString.h src/listOfPartsString/partOfString.cpp src/listOfPartsString/dataOfPartString.cpp)