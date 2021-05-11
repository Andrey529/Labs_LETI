#include "../../headers/informationAboutLetters/elementOfListLetters.h"

elementOfListLetters::elementOfListLetters() {
    this->typeOfLetter = -1;
    this->headFIO = nullptr;
    this->previousFIO = nullptr;
    this->typeOfAddress = -1;
    this->headAddress = nullptr;
    this->previousAddress = nullptr;
    this->countOfStampsInLetter = -1;
    this->weightOfLetter = -1;
    this->nextLetter = nullptr;
}

void elementOfListLetters::setTypeOfLetter(int i) {
    this->typeOfLetter = i;
}

int elementOfListLetters::getTypeOfLetter() const{
    return this->typeOfLetter;
}


void elementOfListLetters::setHeadFIO(partOfString *elem) {
    this->headFIO = elem;
}

partOfString *elementOfListLetters::getHeadFIO() {
    return this->headFIO;
}

void elementOfListLetters::setTypeOfAddress(int i) {
    this->typeOfAddress = i;
}

int elementOfListLetters::getTypeOfAddress() const{
    return this->typeOfAddress;
}

void elementOfListLetters::setHeadAddress(partOfString *elem) {
    this->headAddress = elem;
}

partOfString *elementOfListLetters::getHeadAddress() {
    return this->headAddress;
}

void elementOfListLetters::setCountOfStamps(int i) {
    this->countOfStampsInLetter = i;
}

int elementOfListLetters::getCountOfStamps() const{
    return this->countOfStampsInLetter;
}

void elementOfListLetters::setWeight(int i) {
    this->weightOfLetter = i;
}

int elementOfListLetters::getWeight() const {
    return this->weightOfLetter;
}

void elementOfListLetters::setPreviousFIO(partOfString *elem) {
    this->previousFIO = elem;
}

partOfString *elementOfListLetters::getPreviousFIO() {
    return this->previousFIO;
}

void elementOfListLetters::setPreviousAddress(partOfString *elem) {
    this->previousAddress = elem;
}

partOfString *elementOfListLetters::getPreviousAddress() {
    return this->previousAddress;
}

void elementOfListLetters::setNextLetter(elementOfListLetters *elem) {
    this->nextLetter = elem;
}

elementOfListLetters *elementOfListLetters::getNextLetter() {
    return this->nextLetter;
}

elementOfListLetters::elementOfListLetters(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;
    f_log << "Checking if the input file is empty" << std::endl;
    s = f_in.peek();
    if(s == -1){  // if file with letter information is empty
        std::wcout << "File with information about letters is empty." << std::endl;
        f_log << "File with information about letters is empty." << std::endl;
        return;
    }
}

void elementOfListLetters::addFirstElementOfListLetters(std::wfstream &f_in, std::wfstream &f_log) {


}

