#include "../../headers/listOfPartsString/dataOfPartString.h"

dataOfPartString::dataOfPartString() {
    this->pointerArray = new wchar_t[this->maxLen];
}

dataOfPartString::~dataOfPartString() {
    delete[] this->pointerArray;
}

void dataOfPartString::setSymbol(int i, wchar_t s) {
    *(this->pointerArray+i) = s;
}

wchar_t dataOfPartString::getSymbol(int i) {
    return *(this->pointerArray+i);
}

void dataOfPartString::setMarkInTheEnd(int i) {
    *(this->pointerArray+i) = this->mark;
}

void dataOfPartString::setMark(wchar_t s) {
    this->mark = s;
}

wchar_t dataOfPartString::getMark() const {
    return this->mark;
}

void dataOfPartString::setMaxLen(int i) {
    if(i<=0){
        std::wcout << "Сannot be set maxLen because the entered value is less than or equal to 0" << std::endl;
        return;
    }
    (this->maxLen) = i+1;
}

int dataOfPartString::getMaxLen() const {
    return (this->maxLen)-1;
}