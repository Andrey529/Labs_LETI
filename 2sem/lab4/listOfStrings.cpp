#include "LIstOfStrings.h"


ListOfStrings::ListOfStrings() {
    this->head = nullptr;
    this->previous = nullptr;
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
        delete elem;
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

void ListOfStrings::outputListInConsoleAndInFile(std::fstream &f_out) {
    outputListInConsole();
    outputListInFile(f_out);
}

ListOfStrings::~ListOfStrings() {
    elementOfStringList *elem = getHead();
    elementOfStringList *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }
}

ListOfStrings::ListOfStrings(ListOfStrings &list) {
    elementOfStringList *elemOfBaseList = list.getHead();
    int i = 0;
    while (true){
        elementOfStringList *elemOfNewList = new (std::nothrow) elementOfStringList(*elemOfBaseList);
        if(!elemOfNewList){
            std::cout << "Does not enough memory for new element of CopyList." << std::endl;
            return;
        }
        elemOfBaseList = elemOfBaseList->getNextElement();
        if(i == 0){
            setHead(elemOfNewList);
            if(elemOfBaseList == nullptr){
                elemOfNewList->setNextElement(nullptr);
                break;
            }
            setPrevious(elemOfNewList);
        }
        else if(elemOfBaseList == nullptr){
            previous->setNextElement(elemOfNewList);
            elemOfNewList->setNextElement(nullptr);
            break;
        }
        else{
            previous->setNextElement(elemOfNewList);
            setPrevious(elemOfNewList);
        }
        i++;
    }
}

ListOfStrings ListOfStrings::differenceList1AndList2(ListOfStrings& list1, ListOfStrings& list2) {
    ListOfStrings list3(list1);  // copy of list1
    elementOfStringList *elemOf3List = list3.getHead();

    while(elemOf3List != nullptr){
        elementOfStringList *elemOf2List = list2.getHead();

        elementOfStringList *tmp = elemOf2List;
        int countElements = 0;
        while(true){
            countElements++;
            if(tmp->getNextElement() == nullptr){
                break;
            }
            tmp = tmp->getNextElement();
        }

        situations flag[countElements];
        for(int i=0; i<countElements; i++){
            flag[i] = situations::equal;
        }
        int j = 0;
        while( elemOf2List != nullptr){
            listOfPartsString *partOfElemList3 = elemOf3List->getHead();
            listOfPartsString *partOfElemList2 = elemOf2List->getHead();
            while( (partOfElemList3 != nullptr) && (partOfElemList2 != nullptr) ){
                int i = 0;
                while( (partOfElemList3->getSymbolInfOfPartString(i) != partOfElemList3->getMarkInfofPartString()) &&
                    (partOfElemList2->getSymbolInfOfPartString(i) != partOfElemList2->getMarkInfofPartString()) ){
                    if(partOfElemList3->getSymbolInfOfPartString(i) != partOfElemList2->getSymbolInfOfPartString(i)){
                        flag[j] = situations::notEqual;
                        break;
                    }
                    i++;
                }
                if( (partOfElemList3->getSymbolInfOfPartString(i) == partOfElemList3->getMarkInfofPartString()) &&
                    (partOfElemList2->getSymbolInfOfPartString(i) != partOfElemList2->getMarkInfofPartString()) ){
                    flag[j] = situations::notEqual;
                    break;
                }
                else if( (partOfElemList3->getSymbolInfOfPartString(i) != partOfElemList3->getMarkInfofPartString()) &&
                         (partOfElemList2->getSymbolInfOfPartString(i) == partOfElemList2->getMarkInfofPartString()) ){
                    flag[j] = situations::notEqual;
                    break;
                }
                else{
                    partOfElemList3 = partOfElemList3->getNextElement();
                    partOfElemList2 = partOfElemList2->getNextElement();
                }
            }
            // here
            if( ((partOfElemList3 == nullptr) && (partOfElemList2 != nullptr)) ||
                    ((partOfElemList3 != nullptr) && (partOfElemList2 == nullptr))  ){
                flag[j] = situations::notEqual;
            }
            j++;
            elemOf2List = elemOf2List->getNextElement();
        }

        bool del = false;
        for(int i=0; i<countElements; i++){
            if(flag[i] == situations::equal){
                del = true;
                break;
            }
        }
        if(del){
            if(elemOf3List == list3.getHead()){
                if(elemOf3List->getNextElement() == nullptr){
                    list3.setHead(nullptr);
                    delete elemOf3List;
                    break;
                }
                else{
                    list3.setHead(elemOf3List->getNextElement());
                    elementOfStringList *tmp = elemOf3List;
                    elemOf3List = elemOf3List->getNextElement();
                    delete tmp;
                }
            }
            else if(elemOf3List->getNextElement() == nullptr){
                list3.getPrevious()->setNextElement(nullptr);
                delete elemOf3List;
                break;
            }
            else{
                list3.getPrevious()->setNextElement(elemOf3List->getNextElement());
                elementOfStringList *tmp = elemOf3List;
                elemOf3List = elemOf3List->getNextElement();
                delete tmp;
            }
        }
        else{
            list3.setPrevious(elemOf3List);
            elemOf3List = elemOf3List->getNextElement();
        }
    }

    return list3;
}