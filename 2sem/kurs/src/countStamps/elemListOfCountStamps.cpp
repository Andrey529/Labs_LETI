#include "../../headers/countStamps/elemListOfCountStamps.h"


elemListCountOfStamps::elemListCountOfStamps() {
    this->countStamps = -1;
    this->denominationOfStamps = -1;
    this->nextElem = nullptr;
}

void elemListCountOfStamps::setCountStamps(int i) {
    this->countStamps = i;
}

int elemListCountOfStamps::getCountStamps() const {
    return this->countStamps;
}

void elemListCountOfStamps::setDenomination(int i) {
    this->denominationOfStamps = i;
}

int elemListCountOfStamps::getDenomination() const {
    return this->denominationOfStamps;
}

void elemListCountOfStamps::setNextElement(elemListCountOfStamps *elem) {
    this->nextElem = elem;
}

elemListCountOfStamps *elemListCountOfStamps::getNextElement() {
    return this->nextElem;
}

bool elemListCountOfStamps::reduceCountStamps(int i) {
    if((this->countStamps-i) >= 0){
        this->countStamps = this->countStamps-i;
        return true;
    }
    return false;
}



