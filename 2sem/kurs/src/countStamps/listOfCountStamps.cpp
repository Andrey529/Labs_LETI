#include "../../headers/countStamps/listOfCountStamps.h"

void countOfStamps::setHead(elemListCountOfStamps *elem) {
    this->head = elem;
}

elemListCountOfStamps *countOfStamps::getHead() {
    return this->head;
}

bool countOfStamps::listIsEmpty() {
    return this->head == nullptr;
}

void countOfStamps::setPrevious(elemListCountOfStamps *prev) {
    this->previous = prev;
}

elemListCountOfStamps *countOfStamps::getPrevious() {
    return this->previous;
}


countOfStamps::countOfStamps(std::fstream &f_in) {
    situations flag = addFirstElement(f_in);
    if(flag == situations::emptyFile){
        std::cout << "File with count stamps is empty." << std::endl;
        setHead(nullptr);
    }
    else if(flag == situations::endOfFile){
        std::cout << "File with the count of stamps was read." << std::endl;
    }
    else{
        do{
            flag = addNewElement(f_in);
        }
        while (flag == situations::notLastElement);
        if(flag == situations::endOfFile){
            std::cout << "File with the count of stamps was read!" << std::endl;
        }
    }
}

situations countOfStamps::addFirstElement(std::fstream &f_in) {
    elemListCountOfStamps *elem = new elemListCountOfStamps;
    char s = f_in.peek();
    if(s == -1){
        return situations::emptyFile;
    }
    if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while (s == '\n');
        if(s == -1){
            return situations::emptyFile;
        }
    }
    int count = -1;
    int denom = -1;
    while(true){
        f_in >> count;
        elem->setCountStamps(count);
        do{
            s = f_in.get();
//            if(s == '\n'){
//                return situations::bad;
//            }
//            else if(f_in.eof()){
//                return situations::endOfFile;
//            }
        }
        while(s != '$');
        f_in >> denom;
        elem->setDenomination(denom);
        s = f_in.get();
        if(s == '\n'){
            setHead(elem);
            setPrevious(elem);
            return situations::notLastElement;
        }
        if(f_in.eof()){
            setHead(elem);
            elem->setNextElement(nullptr);
            return situations::endOfFile;
        }
    }
}

situations countOfStamps::addNewElement(std::fstream &f_in) {
    elemListCountOfStamps *elem = new elemListCountOfStamps;
    char s = f_in.peek();
    if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while (s == '\n');
        if(s == -1){
            (getPrevious())->setNextElement(nullptr);
            delete elem;
            return situations::endOfFile;
        }
    }
    if(s == -1){
        (getPrevious())->setNextElement(nullptr);
        delete elem;
        return situations::endOfFile;
    }
    int count = -1;
    int denom = -1;
    while(true){
        f_in >> count;
        elem->setCountStamps(count);
        do{
            s = f_in.get();
//            if(s == '\n'){
//                return situations::bad;
//            }
//            else if(f_in.eof()){
//                return situations::endOfFile;
//            }
        }
        while(s != '$');
        f_in >> denom;
        elem->setDenomination(denom);
        s = f_in.get();
        if(s == '\n'){
            (getPrevious())->setNextElement(elem);
            setPrevious(elem);
            return situations::notLastElement;
        }
        if(f_in.eof()){
            (getPrevious())->setNextElement(elem);
            elem->setNextElement(nullptr);
            return situations::endOfFile;
        }
    }
}


void countOfStamps::outputCountOfStamps() {
    if(listIsEmpty()){
        std::cout << "No data." << std::endl;
        return;
    }
    elemListCountOfStamps *elem = getHead();
    while(elem != nullptr){
        std::cout << elem->getCountStamps() << " stamps denomination of "
                  << elem->getDenomination() << " units." << std::endl;
        elem = elem->getNextElement();
    }
}