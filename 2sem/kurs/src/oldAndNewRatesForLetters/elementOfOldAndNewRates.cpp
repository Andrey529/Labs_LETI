#include "../../headers/oldAndNewRatesForLetters/elementOfOldAndNewRates.h"

void elementOfOldAndNewRates::setTypeOfAddress(bool i) {
    this->typeOfAddress = i;
}

bool elementOfOldAndNewRates::getTypeOfAddress() const{
    return this->typeOfAddress;
}

void elementOfOldAndNewRates::setTypeOfLetter(bool i) {
    this->typeOfLetter = i;
}

bool elementOfOldAndNewRates::getTypeOfLetter() const {
    return this->typeOfLetter;
}

void elementOfOldAndNewRates::setNextElement(elementOfOldAndNewRates *elem) {
    this->nextElement = elem;
}

elementOfOldAndNewRates *elementOfOldAndNewRates::getNextElement() {
    return this->nextElement;
}

void elementOfOldAndNewRates::setHeadValues(rateValues *elem) {
    this->valuesHead = elem;
}

rateValues *elementOfOldAndNewRates::getHeadValues() {
    return this->valuesHead;
}

void elementOfOldAndNewRates::setPreviousValue(rateValues *elem) {
    this->valuePrevious = elem;
}

rateValues *elementOfOldAndNewRates::getPreviousValue() {
    return this->valuePrevious;
}

bool elementOfOldAndNewRates::listNotEmpty() {
    return valuesHead != nullptr;
}

situations elementOfOldAndNewRates::inputDataOfElementOldAndNewRates(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;


    int TypeOfAddress;
    f_in >> TypeOfAddress;
    setTypeOfAddress(TypeOfAddress);

    s = f_in.get();

    int TypeOfLetter;
    f_in >> TypeOfLetter;
    setTypeOfLetter(TypeOfLetter);

    int i=0;
    do{
        auto *value = new (std::nothrow) rateValues;
        if(!value){
            f_log << "Does not enough memory for new rate." << std::endl;
            return situations::notEnoughMemory;
        }
        s = f_in.get();

        int lowerBound;
        f_in >> lowerBound;
        value->setLowerBound(lowerBound);

        s = f_in.get();

        int upperBound;
        f_in >> upperBound;
        value->setUpperBound(upperBound);

        s = f_in.get();
        s = f_in.get();

        int oldPrice;
        f_in >> oldPrice;
        value->setOldPrice(oldPrice);

        s = f_in.get();
        s = f_in.get();

        int newPrice;
        f_in >> newPrice;
        value->setNewPrice(newPrice);

        s = f_in.peek();
        if(s == '\n'){
            if(i == 0){
                setHeadValues(value);
            }
            else{
                getPreviousValue()->setNext(value);
            }
            return situations::notLastElement;
        }
        else if(s == -1){
            if(i == 0){
                setHeadValues(value);
            }
            else{
                getPreviousValue()->setNext(value);
            }
            return situations::endOfFile;
        }
        if(i == 0){
            setHeadValues(value);
            setPreviousValue(value);
        }
        else{
            getPreviousValue()->setNext(value);
            setPreviousValue(value);
        }
        i++;
    }
    while (true);
}

elementOfOldAndNewRates::~elementOfOldAndNewRates() {
    rateValues *value = getHeadValues();
    rateValues *tmp;
    while(value != nullptr){
        tmp = value;
        value = value->getNext();
        delete tmp;
    }
}

void elementOfOldAndNewRates::outputInConsole() {
    if(listNotEmpty()){
        std::wcout << "Type of adress: " << static_cast<int>(getTypeOfAddress()) << std::endl;
        std::wcout << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;
        std::wcout << "Output all rates of this type letter." << std::endl;
        rateValues  *value = getHeadValues();
        while(value != nullptr){
            std::wcout << "Lower bound = " << value->getLowerBound() << ", upper bound = " << value->getUpperBound()
                       << ", old price = " << value->getOldPrice() << ", new price = " << value->getNewPrice() << '.' << std::endl;
            value = value->getNext();
        }
    }
    else{
        std::wcout << "No data of letter rates." << std::endl;
    }
}

void elementOfOldAndNewRates::outputInFile(std::wfstream &f_out, std::wfstream &f_log) {
    if(listNotEmpty()){
        f_log << "Type of adress: " << static_cast<int>(getTypeOfAddress()) << std::endl;
        f_out << "Type of adress: " << static_cast<int>(getTypeOfAddress()) << std::endl;

        f_log << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;
        f_out << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;

        f_log << "Output all rates of this type letter." << std::endl;
        f_out << "Output all rates of this type letter." << std::endl;

        rateValues  *value = getHeadValues();
        while(value != nullptr){
            f_log << "Lower bound = " << value->getLowerBound() << ", upper bound = " << value->getUpperBound()
                       << ", old price = " << value->getOldPrice() << ", new price = " << value->getNewPrice() << '.' << std::endl;
            f_out << "Lower bound = " << value->getLowerBound() << ", upper bound = " << value->getUpperBound()
                       << ", old price = " << value->getOldPrice() << ", new price = " << value->getNewPrice() << '.' << std::endl;
            value = value->getNext();
        }
    }
    else{
        f_log << "No data of letter values." << std::endl;
        f_out << "No data of letter values." << std::endl;
    }
}




