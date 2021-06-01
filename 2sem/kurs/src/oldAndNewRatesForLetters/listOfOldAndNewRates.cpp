#include "../../headers/oldAndNewRatesForLetters/listOfOldAndNewRates.h"

void listOfOldAndNewRatesForLetters::setHead(elementOfOldAndNewRates *elem) {
    this->head = elem;
}

elementOfOldAndNewRates *listOfOldAndNewRatesForLetters::getHead() {
    return this->head;
}

void listOfOldAndNewRatesForLetters::setPrevious(elementOfOldAndNewRates *elem) {
    this->previous = elem;
}

elementOfOldAndNewRates *listOfOldAndNewRatesForLetters::getPrevious() {
    return this->previous;
}

bool listOfOldAndNewRatesForLetters::listNotEmpty() {
    return getHead() != nullptr;
}

bool listOfOldAndNewRatesForLetters::notEnoughMemory(situations situation) {
    return situation == situations::notEnoughMemory;
}

bool listOfOldAndNewRatesForLetters::emptyFile(situations situation) {
    return situation == situations::emptyFile;
}

bool listOfOldAndNewRatesForLetters::endOfFile(situations situation) {
    return situation == situations::endOfFile;
}

bool listOfOldAndNewRatesForLetters::notLastElement(situations situation) {
    return situation == situations::notLastElement;
}


listOfOldAndNewRatesForLetters::listOfOldAndNewRatesForLetters(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;
    f_log << "Checking if the input file with the old and new rates is empty." << std::endl;
    s = f_in.peek();
    if(s == -1){  // if file with rates is empty
        return;        // empty file
    }
    else if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while( (s == '\n') && (s != -1) );
        if(s == -1){
            std::wcout << "File with the old and new rates is empty." << std::endl;
            f_log << "File with the old and new rates is empty." << std::endl;
            return;  // empty file
        }
    }
    situations flag;
    int i=0;
    do{
        elementOfOldAndNewRates *elem = new (std::nothrow) elementOfOldAndNewRates;
        if(!elem){
            f_log << "Does not enough memory for new rate." << std::endl;
            return;
        }
        flag = elem->inputDataOfElementOldAndNewRates(f_in,f_log);
        f_log << "Input rates of " << i+1 << " type of letter." << std::endl;
        if(i == 0){
            if(notLastElement(flag)){
                setHead(elem);
                setPrevious(elem);
            }
            else if(endOfFile(flag)){
                setHead(elem);
                f_log << "File with the old and new rates was read!" << std::endl;
                return;  // first and last letter
            }
            else if(notEnoughMemory(flag)){
                delete elem;
                return;
            }
        }
        else{
            if(notLastElement(flag)){
                getPrevious()->setNextElement(elem);
                setPrevious(elem);
            }
            else if(endOfFile(flag)){
                getPrevious()->setNextElement(elem);
                f_log << "File with the information about letters was read!" << std::endl;
                return;
            }
            else if(notEnoughMemory(flag)){
                getPrevious()->setNextElement(nullptr);
                delete elem;
                return;
            }
        }
        i++;
    }
    while (true);
}

listOfOldAndNewRatesForLetters::~listOfOldAndNewRatesForLetters() {
    elementOfOldAndNewRates *elem = getHead();
    elementOfOldAndNewRates *tmp;
    while (elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }
}

void listOfOldAndNewRatesForLetters::outputInConsole() {
    std::wcout << "---------Output All old and new rates of letters price---------" << std::endl;
    if(listNotEmpty()){
        elementOfOldAndNewRates *elem = getHead();
        int i=0;
        while(elem != nullptr){
            std::wcout << "-------Output rates of " << i+1 << " type of letters-------" << std::endl;
            elem->outputInConsole();
            elem = elem->getNextElement();
            i++;
        }
        std::wcout << "-------All new and old rates of letters were otputed-------" << std::endl << std::endl << std::endl;
    }
    else{
        std::wcout << "No data of letter rates." << std::endl << std::endl << std::endl;
    }
}

void listOfOldAndNewRatesForLetters::outputInFile(std::wfstream &f_out, std::wfstream &f_log) {
    f_log << "---------Output All old and new rates of letters price---------" << std::endl;
    f_out << "---------Output All old and new rates of letters price---------" << std::endl;
    if(listNotEmpty()){
        elementOfOldAndNewRates *elem = getHead();
        int i=0;
        while(elem != nullptr){
            f_log << "-------Output rates of " << i+1 << " type of letters-------" << std::endl;
            f_out << "-------Output rates of " << i+1 << " type of letters-------" << std::endl;
            elem->outputInFile(f_out,f_log);
            elem = elem->getNextElement();
            i++;
        }
        f_log << "-------All new and old rates of letters were otputed-------" << std::endl << std::endl << std::endl;
        f_out << "-------All new and old rates of letters were otputed-------" << std::endl << std::endl << std::endl;
    }
    else{
        f_log << "No data of letter rates." << std::endl << std::endl << std::endl;
        f_out << "No data of letter rates." << std::endl << std::endl << std::endl;
    }
}

void listOfOldAndNewRatesForLetters::outputListOfRatesInConsoleAndInFile(std::wfstream &f_out, std::wfstream &f_log) {
    outputInConsole();
    outputInFile(f_out,f_log);
}
