#include "elementOfStringList.h"

elementOfStringList::elementOfStringList() {
    this->headToListOfPatrsString = nullptr;
    this->previousPartString = nullptr;
    this->nextString = nullptr;
}

elementOfStringList::elementOfStringList(listOfPartsString *head, listOfPartsString *previous, elementOfStringList *next) {
    this->headToListOfPatrsString = head;
    this->previousPartString = previous;
    this->nextString = next;
}

void elementOfStringList::setHead(listOfPartsString *head) {
    this->headToListOfPatrsString = head;
}

listOfPartsString *elementOfStringList::getHead() {
    return this->headToListOfPatrsString;
}

void elementOfStringList::setNextElement(elementOfStringList *next) {
    this->nextString = next;
}

elementOfStringList *elementOfStringList::getNextElement() {
    return this->nextString;
}

void elementOfStringList::setPrevious(listOfPartsString *previous) {
    this->previousPartString = previous;
}

listOfPartsString *elementOfStringList::getPrevious() {
    return this->previousPartString;
}

bool elementOfStringList::listNotEnd(situations situation) {
    return situation == situations::notLastElement;
}

bool elementOfStringList::endOfFile(situations situation){
    return situation == situations::endOfFile;
}

bool elementOfStringList::lastElement(situations situation){
    return situation == situations::lastElement;
}

situations elementOfStringList::inputString(std::fstream &f_in) {
    situations flag = situations::good;
    flag = addFirstPartOfString(f_in);
    if(flag == situations::notEnoughMemory){
        return situations::notEnoughMemory;
    }
    else if(flag == situations::emptyFile){
        return situations::emptyFile;
    }
    else if(flag == situations::endOfFile){
        return situations::endOfFile;
    }
    else if(flag == situations::lastElement){
        return situations::lastElement;
    }
    do{
        flag = addNewPartOfString(f_in);
    }
    while(listNotEnd(flag));
    if (flag == situations::endOfFile){
        return situations::endOfFile;
    }
    else if(flag == situations::notEnoughMemory){
        return situations::notEnoughMemory;
    }
    std::cout << std::endl;
    return situations::lastElement;
}

situations elementOfStringList::addFirstPartOfString(std::fstream &f_in) {
    listOfPartsString *partString = new (std::nothrow) listOfPartsString;
    if(!partString){
        std::cout << "Does not enough memory for element of partsString." << std::endl;
        return situations::notEnoughMemory;
    }

    char s = f_in.peek();
    if(s == -1){ // if file with text is empty
        std::cout << "File with text is empty." << std::endl;
        return situations::emptyFile;
    }

    situations flag = partString->setInf(f_in);
    partString->getInfInConsole();
    if(listNotEnd(flag)){
        setHead(partString);
        setPrevious(partString);
        return situations::notLastElement;
    }
    else if(endOfFile(flag)){
        setHead(partString);
        return situations::endOfFile;
    }
    else{
        setHead(partString);
        return situations::lastElement;
    }
}

situations elementOfStringList::addNewPartOfString(std::fstream &f_in) {
    listOfPartsString *partString = new (std::nothrow) listOfPartsString;
    if(!partString){
        std::cout << "Does not enough memory for element of partsString." << std::endl;
        return situations::notEnoughMemory;
    }
    previousPartString->setNextElement(partString);
    situations flag = partString->setInf(f_in);
    partString->getInfInConsole();
    if(listNotEnd(flag)){
        setPrevious(partString);
        return situations::notLastElement;
    }
    else if(endOfFile(flag)){
        partString->setNextElement(nullptr);
        return situations::endOfFile;
    }
    else{
        partString->setNextElement(nullptr);
        return situations::lastElement;
    }
}
