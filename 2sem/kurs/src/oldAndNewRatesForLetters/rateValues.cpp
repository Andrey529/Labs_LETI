#include "../../headers/oldAndNewRatesForLetters/rateValues.h"

rateValues::rateValues() {
    this->lowerBound = -1;
    this->upperBound = -1;
    this->oldPrice = -1;
    this->newPrice = -1;
    this->next = nullptr;
}

void rateValues::setLowerBound(int i) {
    this->lowerBound = i;
}

int rateValues::getLowerBound() const {
    return this->lowerBound;
}

void rateValues::setUpperBound(int i) {
    this->upperBound = i;
}

int rateValues::getUpperBound() const {
    return this->upperBound;
}

void rateValues::setOldPrice(int i) {
    this->oldPrice = i;
}

int rateValues::getOldPrice() const {
    return this->oldPrice;
}

void rateValues::setNewPrice(int i) {
    this->newPrice = i;
}

int rateValues::getNewPrice() const {
    return this->newPrice;
}

void rateValues::setNext(rateValues *elem) {
    this->next = elem;
}

rateValues *rateValues::getNext() {
    return this->next;
}
