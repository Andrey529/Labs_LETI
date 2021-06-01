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


countOfStamps::countOfStamps(std::wfstream &f_in, std::wfstream &f_log) {
    situations flag = addFirstElement(f_in,f_log);
    if(flag == situations::emptyFile){
        f_log << "File with count stamps is empty." << std::endl;
        std::wcout << "File with count stamps is empty." << std::endl;
    }
    else if(flag == situations::endOfFile){
        f_log << "File with the count of stamps was read." << std::endl;
        std::wcout << "File with the count of stamps was read." << std::endl;
    }
    else{
        do{
            flag = addNewElement(f_in,f_log);
        }
        while (flag == situations::notLastElement);
        f_log << "File with the count of stamps was read!" << std::endl;
    }
}

situations countOfStamps::addFirstElement(std::wfstream &f_in, std::wfstream &f_log) {
    elemListCountOfStamps *elem = new elemListCountOfStamps;
    wchar_t s = f_in.peek();
    f_log << "Checking if the input file with count of stamps is empty." << std::endl;
    if(s == -1){
        delete elem;
        return situations::emptyFile;
    }
    if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while (s == '\n');
        if(s == -1){
            delete elem;
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
            f_log << "In file with count of stamps was read: " << elem->getCountStamps()
            << " stamps denomination of " << elem->getDenomination() << " units." << std::endl;
            return situations::notLastElement;
        }
        if(f_in.eof()){
            setHead(elem);
            elem->setNextElement(nullptr);
            return situations::endOfFile;
        }
    }
}

situations countOfStamps::addNewElement(std::wfstream &f_in, std::wfstream &f_log) {
    elemListCountOfStamps *elem = new elemListCountOfStamps;
    wchar_t s = f_in.peek();
    if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while (s == '\n');
        if(s == -1){
            (getPrevious())->setNextElement(nullptr);
            delete elem;
            f_log << "End of file with count of stamps." << std::endl;
            return situations::endOfFile;
        }
    }
    if(s == -1){
        (getPrevious())->setNextElement(nullptr);
        delete elem;
        f_log << "End of file with count of stamps." << std::endl;
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
            f_log << "In file with count of stamps was read: " << elem->getCountStamps()
                  << " stamps denomination of " << elem->getDenomination() << " units." << std::endl;
            return situations::notLastElement;
        }
        if(f_in.eof()){
            (getPrevious())->setNextElement(elem);
            elem->setNextElement(nullptr);
            f_log << "In file with count of stamps was read: " << elem->getCountStamps()
                  << " stamps denomination of " << elem->getDenomination() << " units." << std::endl;
            f_log << "End of file with count of stamps." << std::endl;
            return situations::endOfFile;
        }
    }
}


countOfStamps::~countOfStamps() {
    elemListCountOfStamps *elem = getHead();
    elemListCountOfStamps *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }
}

void countOfStamps::outputCountOfStampsInFileAndInConsole(std::wfstream &f_result, std::wfstream &f_log) {
    outputCountOfStampsInConsole(f_log);
    outputCountOfStampsInFile(f_result,f_log);
}

void countOfStamps::outputCountOfStampsInFile(std::wfstream &f_result, std::wfstream &f_log) {
    f_log << "-------Output count of stamps in file-------" << std::endl;
    f_result << "-------Output count of stamps in file-------" << std::endl;
    if(listIsEmpty()){
        f_result << "In file of count of stamps No data." << std::endl << std::endl << std::endl;
        f_log << "In file of count of stamps No data." << std::endl << std::endl << std::endl;
        return;
    }
    elemListCountOfStamps *elem = getHead();
    while(elem != nullptr){
        f_result << elem->getCountStamps() << " stamps denomination of "
                  << elem->getDenomination() << " units." << std::endl;
        f_log << elem->getCountStamps() << " stamps denomination of "
              << elem->getDenomination() << " units." << std::endl;
        elem = elem->getNextElement();
    }
    f_log << "-------All count of stamps was outputed in file-------" << std::endl << std::endl << std::endl;
    f_result << "-------All count of stamps was outputed in file-------" << std::endl << std::endl << std::endl;
}

void countOfStamps::outputCountOfStampsInConsole(std::wfstream &f_log) {
    std::wcout << "-------Output count of stamps in console-------" << std::endl;
    if(listIsEmpty()){
        std::wcout << "In file of count of stamps No data" << std::endl << std::endl << std::endl;
        return;
    }
    elemListCountOfStamps *elem = getHead();
    while(elem != nullptr){
        std::wcout << elem->getCountStamps() << " stamps denomination of "
                  << elem->getDenomination() << " units." << std::endl;
        elem = elem->getNextElement();
    }
    std::wcout << "-------All count of stamps was outputed in console-------" << std::endl << std::endl << std::endl;
}

countOfStamps::countOfStamps(countOfStamps *list) {
    elemListCountOfStamps *listElem = list->getHead();
    while(listElem != nullptr){
        auto *elem = new elemListCountOfStamps;
        if(listElem == list->getHead()){
            elem->setDenomination(listElem->getDenomination());
            elem->setCountStamps(listElem->getCountStamps());
            setHead(elem);
            setPrevious(elem);
        }
        else{
            elem->setDenomination(listElem->getDenomination());
            elem->setCountStamps(listElem->getCountStamps());
            getPrevious()->setNextElement(elem);
            setPrevious(elem);
        }
        listElem = listElem->getNextElement();
    }
}

bool countOfStamps::haveStamps() {
    elemListCountOfStamps *elem = getHead();
    while(elem != nullptr){
        if(elem->getCountStamps() > 0){
            return true;
        }
        elem = elem->getNextElement();
    }
    return false;
}

int countOfStamps::getStampOfMaxDenomination(int ogranichitel) {
    elemListCountOfStamps *elem = getHead();
    int max = -1;
    while(elem != nullptr){
        if( (elem->getCountStamps() > 0) && (elem->getDenomination() <= ogranichitel) && (elem->getDenomination() > max) ){
            max = elem->getDenomination();
        }
        elem = elem->getNextElement();
    }
    return max;
}
