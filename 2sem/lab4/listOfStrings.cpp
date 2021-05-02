#include "LIstOfStrings.h"

ListOfStrings::ListOfStrings() {
    this->head = nullptr;
    this->previous = nullptr;
}

ListOfStrings::ListOfStrings(elementOfStringList *head, elementOfStringList *previous) {
    this->head = head;
    this->previous = previous;
}

void ListOfStrings::setHead(elementOfStringList *head) {
    this->head = head;
}

elementOfStringList *ListOfStrings::getHead() {
    return this->head;
}

void ListOfStrings::setPrevious(elementOfStringList *previous) {
    this->previous = previous;
}

elementOfStringList *ListOfStrings::getPrevious() {
    return this->previous;
}

situations ListOfStrings::addFirstElement(std::fstream &f_in) {
    elementOfStringList *elem = new (std::nothrow) elementOfStringList;
    if(!elem){
        std::cout << "Does not enough memory for element of ListStrings." << std::endl;
        return situations::notEnoughMemory;
    }
    situations flag = elem->inputString(f_in);
    if(flag == situations::notEnoughMemory){
        return situations::notEnoughMemory;
    }
    else if(flag == situations::emptyFile){
        return situations::emptyFile;
    }
    else if(flag == situations::endOfFile){
        setHead(elem);
        return situations::endOfFile;
    }
    else if(flag == situations::lastElement){
        setHead(elem);
        setPrevious(elem);
        return situations::lastElement;
    }
    return situations::good;
}

situations ListOfStrings::addNewElement(std::fstream &f_in) {
    elementOfStringList *elem = new (std::nothrow) elementOfStringList;
    if(!elem){
        std::cout << "Does not enough memory for element of ListStrings." << std::endl;
        return situations::notEnoughMemory;
    }
    situations flag = elem->inputString(f_in);
    if(flag == situations::notEnoughMemory){
        return situations::notEnoughMemory;
    }
    else if(flag == situations::endOfFile){
        previous->setNextElement(elem);
        elem->setNextElement(nullptr);
        return situations::endOfFile;
    }
    else if(flag == situations::lastElement){
        previous->setNextElement(elem);
        setPrevious(elem);
        return situations::lastElement;
    }
    return situations::good;
}

situations ListOfStrings::inputList(std::fstream &f_in) {
    situations flag = addFirstElement(f_in);
    if(flag == situations::notEnoughMemory){
        return situations::notEnoughMemory;
    }
    else if(flag == situations::emptyFile){
        return situations::emptyFile;
    }
    else if(flag == situations::endOfFile){
        return situations::endOfFile;
    }
    do{
        flag = addNewElement(f_in);
    }
    while (flag == situations::lastElement);
    return situations::good;

}