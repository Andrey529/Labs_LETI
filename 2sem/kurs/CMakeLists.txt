cmake_minimum_required(VERSION 3.17)
project(kurs)

set(CMAKE_CXX_STANDARD 17)

add_executable(kurs main.cpp
        src/countStamps/elemListOfCountStamps.cpp
        src/countStamps/listOfCountStamps.cpp
        src/functions/functions.cpp
        src/informationAboutLetters/elementOfListLetters.cpp
        src/informationAboutLetters/listOfLetters.cpp
        src/listOfPartsString/partOfString.cpp
        src/listOfPartsString/dataOfPartString.cpp
        headers/oldAndNewRatesForLetters/listOfOldAndNewRates.h
        src/oldAndNewRatesForLetters/listOfOldAndNewRates.cpp
        headers/oldAndNewRatesForLetters/elementOfOldAndNewRates.h
        src/oldAndNewRatesForLetters/elementOfOldAndNewRates.cpp)