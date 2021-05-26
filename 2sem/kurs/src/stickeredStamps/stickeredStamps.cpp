#include "../../headers/stickeredStamps/stickeredStamps.h"

void stickekeredStamps::setHead(elementOfStikeredStamps *elem) {
    this->head = elem;
}

elementOfStikeredStamps *stickekeredStamps::getHead() {
    return this->head;
}

void stickekeredStamps::setPrevious(elementOfStikeredStamps *elem) {
    this->previous = elem;
}

elementOfStikeredStamps *stickekeredStamps::getPrevious() {
    return this->previous;
}

stickekeredStamps::~stickekeredStamps() {
    elementOfStikeredStamps *elem = getHead();
    elementOfStikeredStamps *tmp;
    while (elem != nullptr){
        tmp = elem;
        elem = elem->getNextStamp();
        delete tmp;
    }
}

void stickekeredStamps::setElement(int denomination, int needUnits, int countStamps) {
    auto *elem = new elementOfStikeredStamps;
    if(getHead() == nullptr){
        elem->setDenomination(denomination);
        elem->setNeedUnits(needUnits);
        elem->setCountStamps(countStamps);
        setHead(elem);
        setPrevious(elem);
    }
    else{
        elem->setDenomination(denomination);
        elem->setNeedUnits(needUnits);
        elem->setCountStamps(countStamps);
        getPrevious()->setNextStamp(elem);
        setPrevious(elem);
    }
}

stickekeredStamps::stickekeredStamps(stickekeredStamps *list) {
    elementOfStikeredStamps *listElem = list->getHead();
    while (listElem != nullptr){
        auto *elem = new elementOfStikeredStamps;
        if(listElem == list->getHead()){
            elem->setDenomination(listElem->getDenomination());
            elem->setNeedUnits(listElem->getNeedUnits());
            elem->setCountStamps(listElem->getCountStamps());
            setHead(elem);
            setPrevious(elem);
        }
        else{
            elem->setDenomination(listElem->getDenomination());
            elem->setNeedUnits(listElem->getNeedUnits());
            elem->setCountStamps(listElem->getCountStamps());
            getPrevious()->setNextStamp(elem);
            setPrevious(elem);
        }
        listElem = listElem->getNextStamp();
    }
}

void stickekeredStamps::outputListInConsole() {
    elementOfStikeredStamps *elem = getHead();
    while(elem != nullptr){
        std::wcout << "Denomination of stamp = " << elem->getDenomination()
        << " and stamp stickered in letter with " << elem->getNeedUnits() << " need units and "
        << elem->getCountStamps() << " count of stamps before stickering." << std::endl;
        elem = elem->getNextStamp();
    }
}

void stickekeredStamps::outputListInFile(std::wfstream &f_log, std::wfstream &f_out) {
    elementOfStikeredStamps *elem = getHead();
    while(elem != nullptr){
        f_log << "Denomination of stamp = " << elem->getDenomination()
                   << " and stamp stickered in letter with " << elem->getNeedUnits() << " need units and "
                   << elem->getCountStamps() << " count of stamps before stickering." << std::endl;
        f_out << "Denomination of stamp = " << elem->getDenomination()
              << " and stamp stickered in letter with " << elem->getNeedUnits() << " need units and "
              << elem->getCountStamps() << " count of stamps before stickering." << std::endl;
        elem = elem->getNextStamp();
    }
}

void stickekeredStamps::outputList(std::wfstream &f_log, std::wfstream &f_out) {
    outputListInConsole();
    outputListInFile(f_log,f_out);
}

stickekeredStamps::stickekeredStamps() {
    this->setHead(nullptr);
    this->setPrevious(nullptr);
}

