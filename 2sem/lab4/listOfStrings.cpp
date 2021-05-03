#include "LIstOfStrings.h"

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

bool ListOfStrings::listNotEmpty() {
    return head != nullptr;
}

bool ListOfStrings::notEnoughMemory(situations situation) {
    return situation == situations::notEnoughMemory;
}
bool ListOfStrings::emptyFile(situations situation) {
    return situation == situations::emptyFile;
}
bool ListOfStrings::endOfFile(situations situation) {
    return situation == situations::endOfFile;
}
bool ListOfStrings::lastElement(situations situation) {
    return situation == situations::lastElement;
}

ListOfStrings::ListOfStrings(std::fstream &f_in) {
    situations flag = addFirstElement(f_in);
    if(notEnoughMemory(flag)){
        return;
    }
    else if(emptyFile(flag)){
        return;
    }
    else if(endOfFile(flag)){
        return;
    }

    do{
        flag = addNewElement(f_in);
    }
    while (flag == situations::lastElement);
}
situations ListOfStrings::addFirstElement(std::fstream &f_in) {
    elementOfStringList *elem = new (std::nothrow) elementOfStringList;
    if(!elem){
        std::cout << "Does not enough memory for element of ListStrings." << std::endl;
        return situations::notEnoughMemory;
    }

    situations flag = elem->inputString(f_in);
    if(notEnoughMemory(flag)){
        return situations::notEnoughMemory;
    }
    else if(emptyFile(flag)){
        return situations::emptyFile;
    }
    else if(endOfFile(flag)){
        setHead(elem);
        elem->setNextElement(nullptr);
        return situations::endOfFile;
    }
    else if(lastElement(flag)){
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
    if(notEnoughMemory(flag)){
        return situations::notEnoughMemory;
    }
    else if(endOfFile(flag)){
        previous->setNextElement(elem);
        elem->setNextElement(nullptr);
        return situations::endOfFile;
    }
    else if(lastElement(flag)){
        previous->setNextElement(elem);
        setPrevious(elem);
        return situations::lastElement;
    }
    return situations::good;
}

void ListOfStrings::outputListInConsole() {
    elementOfStringList *elem = getHead();
    std::cout << "Head" << std::endl << "  |  " << std::endl;
    while(true){
        elem->outputStringInConsole();
        elem = elem->getNextElement();
        if(elem == nullptr){
            break;
        }
    }
    std::cout << " | " << std::endl << "End" << std::endl;
}
void ListOfStrings::outputListInFile(std::fstream &f_out) {
    elementOfStringList *elem = getHead();

    f_out << "Head" << std::endl << "  |  " << std::endl;
    while(true){
        elem->outputStringInFile(f_out);
        elem = elem->getNextElement();
        if(elem == nullptr){
            break;
        }
    }
    f_out << " | " << std::endl << "End" << std::endl;
}
