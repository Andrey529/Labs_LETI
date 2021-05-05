#include "elementOfStringList.h"

elementOfStringList::elementOfStringList() {
    this->headToListOfPatrsString = nullptr;
    this->previousPartString = nullptr;
    this->nextString = nullptr;
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
bool elementOfStringList::notEnoughMemory(situations situation) {
    return situation == situations::notEnoughMemory;
}
bool elementOfStringList::emptyFile(situations situation) {
    return situation == situations::emptyFile;
}

bool elementOfStringList::listNotEmpty() {
    return headToListOfPatrsString != nullptr;
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
    if(listNotEnd(flag)){
        setHead(partString);
        setPrevious(partString);
        return situations::notLastElement;
    }
    else if(endOfFile(flag)){
        setHead(partString);
        std::cout << "End of File." << std::endl;
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

situations elementOfStringList::inputString(std::fstream &f_in) {
    situations flag = addFirstPartOfString(f_in);
    if(notEnoughMemory(flag)){
        return situations::notEnoughMemory;
    }
    else if(emptyFile(flag)){
        return situations::emptyFile;
    }
    else if(endOfFile(flag)){
        return situations::endOfFile;
    }
    else if(lastElement(flag)){
        return situations::lastElement;
    }
    else{
        do{
            flag = addNewPartOfString(f_in);
        }
        while (flag == situations::notLastElement);
        if (notEnoughMemory(flag)){
            return situations::notEnoughMemory;
        }
        else if(endOfFile(flag)){
            return situations::endOfFile;
        }
        else if(lastElement(flag)){
            return situations::lastElement;
        }
        else return situations::notLastElement;
    }
}
void elementOfStringList::outputStringInConsole() {
    listOfPartsString *partString = getHead();

    while(true){
        partString->getInfInConsole();
        partString = partString->getNextElement();
        if(partString == nullptr){
            break;
        }
    }
    std::cout << "X" << std::endl;
}
void elementOfStringList::outputStringInFile(std::fstream &f_out) {
    listOfPartsString *partString = getHead();

    while(true){
        partString->getInfInFile(f_out);
        partString = partString->getNextElement();
        if(partString == nullptr){
            break;
        }
    }
    f_out << "X" << std::endl;
}

elementOfStringList::~elementOfStringList() {
    listOfPartsString *partString = getHead();
    listOfPartsString *tmp;

    while(partString != nullptr){
        tmp = partString;
        partString = partString->getNextElement();
        delete tmp;
    }
}

elementOfStringList::elementOfStringList(elementOfStringList &string) {
    listOfPartsString *elementOfBaseString = string.getHead();
    int i = 0;
    while (true){
        listOfPartsString *elemOfNewString = new (std::nothrow) listOfPartsString(*elementOfBaseString);
        if(!elemOfNewString){
            std::cout << "Does not enough memory for new element of CopyString." << std::endl;
            return;
        }
        elementOfBaseString = elementOfBaseString->getNextElement();
        if(i == 0){
            setHead(elemOfNewString);
            if(elementOfBaseString == nullptr){
                elemOfNewString->setNextElement(nullptr);
                break;
            }
            setPrevious(elemOfNewString);
        }
        else if(elementOfBaseString == nullptr){
            previousPartString->setNextElement(elemOfNewString);
            elemOfNewString->setNextElement(nullptr);
            break;
        }
        else{
            previousPartString->setNextElement(elemOfNewString);
            setPrevious(elemOfNewString);
        }
        i++;
    }
}
