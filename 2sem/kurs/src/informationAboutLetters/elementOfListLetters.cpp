#include "../../headers/informationAboutLetters/elementOfListLetters.h"

elementOfListLetters::elementOfListLetters() {
    this->typeOfLetter = -1;
    this->headFIO = nullptr;
    this->typeOfAddress = -1;
    this->headAddress = nullptr;
    this->countOfStampsInLetter = -1;
    this->weughtOfLetter = -1;
}

elementOfListLetters::elementOfListLetters(std::fstream &f_in, std::fstream &f_log) {

}