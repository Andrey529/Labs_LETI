#include "../../headers/informationAboutLetters/elementOfListLetters.h"

elementOfListLetters::elementOfListLetters() {
    this->typeOfLetter = false;
    this->headFIO = nullptr;
    this->previousFIO = nullptr;
    this->typeOfAddress = false;
    this->headAddress = nullptr;
    this->previousAddress = nullptr;
    this->countOfStampsInLetter = -1;
    this->weightOfLetter = -1;
    this->nextLetter = nullptr;
}

void elementOfListLetters::setTypeOfLetter(bool i) {
    this->typeOfLetter = i;
}

bool elementOfListLetters::getTypeOfLetter() const{
    return this->typeOfLetter;
}

void elementOfListLetters::setHeadFIO(partOfString *elem) {
    this->headFIO = elem;
}

partOfString *elementOfListLetters::getHeadFIO() {
    return this->headFIO;
}

void elementOfListLetters::setTypeOfAddress(bool i) {
    this->typeOfAddress = i;
}

bool elementOfListLetters::getTypeOfAddress() const{
    return this->typeOfAddress;
}

void elementOfListLetters::setHeadAddress(partOfString *elem) {
    this->headAddress = elem;
}

partOfString *elementOfListLetters::getHeadAddress() {
    return this->headAddress;
}

void elementOfListLetters::setCountOfStamps(int i) {
    this->countOfStampsInLetter = i;
}

int elementOfListLetters::getCountOfStamps() const{
    return this->countOfStampsInLetter;
}

void elementOfListLetters::setWeight(int i) {
    this->weightOfLetter = i;
}

int elementOfListLetters::getWeight() const {
    return this->weightOfLetter;
}

void elementOfListLetters::setPreviousFIO(partOfString *elem) {
    this->previousFIO = elem;
}

partOfString *elementOfListLetters::getPreviousFIO() {
    return this->previousFIO;
}

void elementOfListLetters::setPreviousAddress(partOfString *elem) {
    this->previousAddress = elem;
}

partOfString *elementOfListLetters::getPreviousAddress() {
    return this->previousAddress;
}

void elementOfListLetters::setNextLetter(elementOfListLetters *elem) {
    this->nextLetter = elem;
}

elementOfListLetters *elementOfListLetters::getNextLetter() {
    return this->nextLetter;
}

bool elementOfListLetters::NotLastElement(situations situation) {
    return situation == situations::notLastElement;
}
bool elementOfListLetters::endOfFile(situations situation){
    return situation == situations::endOfFile;
}
bool elementOfListLetters::lastElement(situations situation){
    return situation == situations::lastElement;
}
bool elementOfListLetters::notEnoughMemory(situations situation) {
    return situation == situations::notEnoughMemory;
}
bool elementOfListLetters::emptyFile(situations situation) {
    return situation == situations::emptyFile;
}

bool elementOfListLetters::listNotEmpty(partOfString *head) {
    return head != nullptr;
}

situations elementOfListLetters::inputDataOfElementOfListLetters(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;
    int typeOfLetter;
    f_in >> typeOfLetter;
    setTypeOfLetter(typeOfLetter);

    s = f_in.get();
    wchar_t ogranichitel = s;
    situations flag = inputFIO(f_in,f_log,ogranichitel);
    if(notEnoughMemory(flag)){
        f_log << "Does not enough memory for FIO." << std::endl;
        return situations::notEnoughMemory;
    }
    else if(endOfFile(flag)){
        return situations::endOfFile;
    }

    int typeOfAddress;
    f_in >> typeOfAddress;
    setTypeOfAddress(typeOfAddress);

    s = f_in.get();
    ogranichitel = s;
    inputAddress(f_in,f_log,ogranichitel);

    int countStamps;
    f_in >> countStamps;
    setCountOfStamps(countStamps);

    s = f_in.get();

    int weight;
    f_in >> weight;
    setWeight(weight);

    s = f_in.get();
    if(s == '\n'){
        return situations::notLastElement;
    }
    else if(f_in.eof()){
        return situations::endOfFile;
    }
    return situations::bad;
}


situations elementOfListLetters::inputFIO(std::wfstream &f_in, std::wfstream &f_log, wchar_t ogranichitel) {
    int i = 0;
    situations flag;
    do{
        partOfString *part = new (std::nothrow) partOfString;
        if(!part){
            return situations::notEnoughMemory;
        }
        flag = part->setInf(f_in,f_log,ogranichitel);
        if(i == 0){
            if(NotLastElement(flag)){
                setHeadFIO(part);
                setPreviousFIO(part);
            }
            else if(endOfFile(flag)){
                setHeadFIO(part);
                return situations::endOfFile;
            }
            else{  // last element (last part string) and it is first part string
                setHeadFIO(part);
                return situations::lastElement;
            }
        }
        else{
            if(NotLastElement(flag)){
                getPreviousFIO()->setNextElement(part);
                setPreviousFIO(part);
            }
            else if(endOfFile(flag)){
                getPreviousFIO()->setNextElement(part);
                return situations::endOfFile;
            }
            else{  // last element (last part string)
                getPreviousFIO()->setNextElement(part);
                return situations::lastElement;
            }
        }
        i++;
    }
    while(true);
}

situations elementOfListLetters::inputAddress(std::wfstream &f_in, std::wfstream &f_log, wchar_t ogranichitel) {
    int i = 0;
    situations flag;
    do{
        partOfString *part = new (std::nothrow) partOfString;
        if(!part){
            f_log << "Does not enough memory for element of partsString." << std::endl;
            return situations::notEnoughMemory;
        }
        flag = part->setInf(f_in,f_log,ogranichitel);
        if(i == 0){
            if(NotLastElement(flag)){
                setHeadAddress(part);
                setPreviousAddress(part);
            }
            else if(endOfFile(flag)){
                setHeadAddress(part);
                return situations::endOfFile;
            }
            else{  // last element (last part string) and it is first part string
                setHeadAddress(part);
                return situations::lastElement;
            }
        }
        else{
            if(NotLastElement(flag)){
                getPreviousAddress()->setNextElement(part);
                setPreviousAddress(part);
            }
            else if(endOfFile(flag)){
                getPreviousAddress()->setNextElement(part);
                return situations::endOfFile;
            }
            else{  // last element (last part string)
                getPreviousAddress()->setNextElement(part);
                return situations::lastElement;
            }
        }
        i++;
    }
    while(true);
}

void elementOfListLetters::outputDataOfElementOfListLettersInConsole(std::wfstream &f_log) {
    std::wcout << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;

    partOfString *elem = getHeadFIO();
    std::wcout << "FIO: ";
    while(elem != nullptr){
        elem->getInfInConsole();
        elem = elem->getNextElement();
    }
    std::wcout << std::endl;

    std::wcout << "Type of address: " << static_cast<int>(getTypeOfAddress()) << std::endl;

    elem = getHeadAddress();
    std::wcout << "Address: ";
    while(elem != nullptr){
        elem->getInfInConsole();
        elem = elem->getNextElement();
    }
    std::wcout << std::endl;

    std::wcout << "Count of stamps in letter = " << static_cast<int>(getCountOfStamps()) << std::endl;
    std::wcout << "Weight of letter = " << static_cast<int>(getWeight()) << std::endl;
}

void elementOfListLetters::outputDataOfElementOfListLettersInFile(std::wfstream &f_out, std::wfstream &f_log) {


    f_out << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;
    f_log << "Type of letter: " << static_cast<int>(getTypeOfLetter()) << std::endl;

    partOfString *elem = getHeadFIO();
    f_out << "FIO: ";
    f_log << "FIO: ";
    while(elem != nullptr){
        elem->getInfInFile(f_out);
        elem->getInfInFile(f_log);
        elem = elem->getNextElement();
    }
    f_out << std::endl;
    f_log << std::endl;

    f_out << "Type of address: " << static_cast<int>(getTypeOfAddress()) << std::endl;
    f_log << "Type of address: " << static_cast<int>(getTypeOfAddress()) << std::endl;

    elem = getHeadAddress();
    f_out << "Address: ";
    f_log << "Address: ";
    while(elem != nullptr){
        elem->getInfInFile(f_out);
        elem->getInfInFile(f_log);
        elem = elem->getNextElement();
    }
    f_out << std::endl;
    f_log << std::endl;

    f_out << "Count of stamps in letter = " << static_cast<int>(getCountOfStamps()) << std::endl;
    f_log << "Count of stamps in letter = " << static_cast<int>(getCountOfStamps()) << std::endl;

    f_out << "Weight of letter = " << static_cast<int>(getWeight()) << std::endl;
    f_log << "Weight of letter = " << static_cast<int>(getWeight()) << std::endl;
}

elementOfListLetters::~elementOfListLetters() {
    partOfString *elem = getHeadFIO();
    partOfString *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }

    elem = getHeadAddress();
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }
}

void elementOfListLetters::setOldPrice(int i) {
    this->oldPrice = i;
}

int elementOfListLetters::getOldPrice() const {
    return this->oldPrice;
}

void elementOfListLetters::setNewPrice(int i) {
    this->newPrice = i;
}

int elementOfListLetters::getNewPrice() const {
    return this->newPrice;
}

void elementOfListLetters::setNeedUnits(int i) {
    this->needUnits = i;
}

int elementOfListLetters::getNeedUnits() const {
    return this->needUnits;
}

void elementOfListLetters::setNeedToSort(bool i) {
    this->needToSort = i;
}

bool elementOfListLetters::getNeedToSort() const{
    return this->needToSort;
}

void elementOfListLetters::setIndex(int i) {
    this->index = i;
}

int elementOfListLetters::getIndex() const {
    return this->index;
}

elementOfListLetters::elementOfListLetters(elementOfListLetters *elem) {
    setTypeOfLetter(elem->getTypeOfLetter());
    setTypeOfAddress(elem->getTypeOfAddress());
    setCountOfStamps(elem->getCountOfStamps());
    setWeight(elem->getWeight());
    setOldPrice(elem->getOldPrice());
    setNewPrice(elem->getNewPrice());
    setNeedUnits(elem->getNeedUnits());
    setNeedToSort(elem->getNeedToSort());
    setIndex(elem->getIndex());

    setPreviousFIO(nullptr);
    setPreviousAddress(nullptr);

    partOfString *partBase = elem->getHeadFIO();
    while(partBase != nullptr){
        auto *partNew = new partOfString(partBase);
        if(partBase == elem->getHeadFIO()){
            setHeadFIO(partNew);
            setPreviousFIO(partNew);
        }
        else{
            getPreviousFIO()->setNextElement(partNew);
            setPreviousFIO(partNew);
        }
        partBase = partBase->getNextElement();
    }

    partBase = elem->getHeadAddress();
    while(partBase != nullptr){
        auto *partNew = new partOfString(partBase);
        if(partBase == elem->getHeadAddress()){
            setHeadAddress(partNew);
            setPreviousAddress(partNew);
        }
        else{
            getPreviousAddress()->setNextElement(partNew);
            setPreviousAddress(partNew);
        }
        partBase = partBase->getNextElement();
    }
}

void elementOfListLetters::setNeedStamps(int i) {
    this->needStamps = i;
}

int elementOfListLetters::getNeedStamps() const {
    return this->needStamps;
}
