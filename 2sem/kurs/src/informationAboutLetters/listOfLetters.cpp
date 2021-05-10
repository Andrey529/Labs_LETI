#include "../../headers/informationAboutLetters/listOfLetters.h"

bool listOfLetters::listIsEmpty() {
    return this->head == nullptr;
}

void listOfLetters::setHead(elementOfListLetters *elem) {
    this->head = elem;
}

elementOfListLetters *listOfLetters::getHead() {
    return this->head;
}

void listOfLetters::setPrevious(elementOfListLetters *elem) {
    this->previous = elem;
}

elementOfListLetters *listOfLetters::getPrevious() {
    return this->previous;
}

listOfLetters::listOfLetters() {
    this->head = nullptr;
    this->previous = nullptr;
}

listOfLetters::listOfLetters(std::fstream &f_in, std::fstream &f_log) {

}
