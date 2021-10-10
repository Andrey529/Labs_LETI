#include "../headers/data.h"

int data::getNumber() const {
    return this->number;
}

void data::setNumber(int number) {
    this->number = number;
}

data *data::getNextElem() const {
    return this->nextElem;
}

void data::setNextElem(data *elem) {
    this->nextElem = elem;
}

data::~data() = default;


