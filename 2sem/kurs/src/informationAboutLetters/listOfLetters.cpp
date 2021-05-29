#include "../../headers/informationAboutLetters/listOfLetters.h"

bool listOfLetters::listNotEmpty() {
    return getHead() != nullptr;
}

void listOfLetters::setHead(elementOfListLetters *elem) {
    this->head = elem;
}

elementOfListLetters *listOfLetters::getHead() {
    return this->head;
}

void listOfLetters::setPrevious(elementOfListLetters *elem) {
    this->previous = elem;
}

elementOfListLetters *listOfLetters::getPrevious() {
    return this->previous;
}

bool listOfLetters::notEnoughMemory(situations situation) {
    return situation == situations::notEnoughMemory;
}

bool listOfLetters::emptyFile(situations situation) {
    return situation == situations::emptyFile;
}

bool listOfLetters::endOfFile(situations situation) {
    return situation == situations::endOfFile;
}

bool listOfLetters::lastLetter(situations situation) {
    return situation == situations::lastElement;
}

bool listOfLetters::notLastLetter(situations situation) {
    return situation == situations::notLastElement;
}

listOfLetters::listOfLetters(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;
    f_log << "Checking if the input file with information about letters is empty." << std::endl;
    s = f_in.peek();
    if(s == -1){  // if file with letter information is empty
        return;        // empty file
    }
    else if(s == '\n'){
        do{
            s = f_in.get();
            s = f_in.peek();
        }
        while( (s == '\n') && (s != -1) );
        if(s == -1){
            std::wcout << "File with information about letters is empty." << std::endl;
            f_log << "File with information about letters is empty." << std::endl;
            return;  // empty file
        }
    }


    situations flag;
    int i = 0;
    do{
        elementOfListLetters *elem = new (std::nothrow) elementOfListLetters;
        if(!elem){
            f_log << "Does not enough memory for new letter." << std::endl;
            return;
        }
        flag = elem->inputDataOfElementOfListLetters(f_in,f_log);
        f_log << "Input data of " << i+1 << " letter." << std::endl;
        if(i == 0){
            if(notLastLetter(flag)){
                setHead(elem);
                setPrevious(elem);
            }
            else if(endOfFile(flag)){
                setHead(elem);
                f_log << "File with the information about letters was read!" << std::endl;
                return;  // first and last letter
            }
        }
        else{
            if(notLastLetter(flag)){
                getPrevious()->setNextLetter(elem);
                setPrevious(elem);
            }
            else if(endOfFile(flag)){
                getPrevious()->setNextLetter(elem);
                f_log << "File with the information about letters was read!" << std::endl;
                return;
            }
        }
        i++;
    }
    while (true);
}

listOfLetters::~listOfLetters() {
    elementOfListLetters *elem = getHead();
    elementOfListLetters *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextLetter();
        delete tmp;
    }
}

void listOfLetters::outputInConsole(std::wfstream &f_log) {
    if(listNotEmpty()){
        std::wcout << "-------Output data of letters in console-------" << std::endl;
        elementOfListLetters *elem = getHead();
        int i=0;
        while(elem != nullptr){
            std::wcout << "-------Data of " << i+1 << " letter-------" << std::endl;
            elem->outputDataOfElementOfListLettersInConsole(f_log);
            elem = elem->getNextLetter();
            i++;
        }
        std::wcout << "-------All data about letters was outputed-------" << std::endl << std::endl << std::endl;
    }
    else{
        std::wcout << "File with information about letters is empty." << std::endl << std::endl << std::endl;
    }
}

void listOfLetters::outputInFile(std::wfstream &f_out, std::wfstream &f_log) {
    if(listNotEmpty()){
        f_log << "-------Output data of letters in file-------" << std::endl;
        f_out << "-------Output data of letters in file-------" << std::endl;
        elementOfListLetters *elem = getHead();
        int i=0;
        while(elem != nullptr){
            f_log << "-------Data of " << i+1 << " letter-------" << std::endl;
            f_out << "-------Data of " << i+1 << " letter-------" << std::endl;
            elem->outputDataOfElementOfListLettersInFile(f_out,f_log);
            elem = elem->getNextLetter();
            i++;
        }
        f_log << "-------All data about letters was outputed-------" << std::endl << std::endl << std::endl;
        f_out << "-------All data about letters was outputed-------" << std::endl << std::endl << std::endl;
    }
    else{
        f_out << "File with information about letters is empty." << std::endl << std::endl << std::endl;
        f_log << "File with information about letters is empty." << std::endl << std::endl << std::endl;
    }
}

void listOfLetters::outputListOfLettersInConsoleAndInFile(std::wfstream &f_out, std::wfstream &f_log) {
    outputInConsole(f_log);
    outputInFile(f_out,f_log);
}

int listOfLetters::getCountOfLetters() {
    int i = 0;
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        i++;
        elem = elem->getNextLetter();
    }
    return i;
}

elementOfListLetters *listOfLetters::getLetterByNumber(int i) {
    int j = 0;
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        if(j == i){
            break;
        }
        j++;
        elem = elem->getNextLetter();
    }
    return elem;
}

elementOfListLetters *listOfLetters::getPreviousLetterByNumber(int i) {
    int j = 0;
    if(i == 0){
        return nullptr;
    }
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        if(j == (i-1)){
            break;
        }
        j++;
        elem = elem->getNextLetter();
    }
    return elem;
}

void listOfLetters::swapLettersByNumbers(int i, int j) {
    if(i == j){
        return;
    }
    elementOfListLetters *elem1;
    elementOfListLetters *previousElem1;
    elementOfListLetters *elem2;
    elementOfListLetters *previousElem2;
    elementOfListLetters *tmp1;
    elementOfListLetters *tmp2;

    if( ((i-j) == 1) || ((j-i) == 1) ){
        if(i == 0){
            elem1 = getLetterByNumber(i);
            elem2 = getLetterByNumber(j);

            tmp1 = elem1;
            tmp2 = elem2->getNextLetter();
            setHead(elem2);
            elem2->setNextLetter(tmp1);
            tmp1->setNextLetter(tmp2);
        }
        else if(j == 0){
            elem1 = getLetterByNumber(j);
            elem2 = getLetterByNumber(i);

            tmp1 = elem1;
            tmp2 = elem2->getNextLetter();
            setHead(elem2);
            elem2->setNextLetter(tmp1);
            tmp1->setNextLetter(tmp2);
        }
        else{
            if(i < j){
                elem1 = getLetterByNumber(i);
                elem2 = getLetterByNumber(j);
                previousElem1 = getPreviousLetterByNumber(i);
                previousElem2 = getPreviousLetterByNumber(j);

                tmp1 = elem1;
                tmp2 = elem2->getNextLetter();

                previousElem1->setNextLetter(elem2);
                elem2->setNextLetter(tmp1);

                tmp1->setNextLetter(tmp2);
            }
            else{
                elem1 = getLetterByNumber(j);
                elem2 = getLetterByNumber(i);
                previousElem1 = getPreviousLetterByNumber(j);
                previousElem2 = getPreviousLetterByNumber(i);

                tmp1 = elem1;
                tmp2 = elem2->getNextLetter();

                previousElem1->setNextLetter(elem2);
                elem2->setNextLetter(tmp1);

                tmp1->setNextLetter(tmp2);
            }

        }
    }
    else{
        if(i == 0){
            elem1 = getLetterByNumber(i);
            elem2 = getLetterByNumber(j);
            previousElem2 = getPreviousLetterByNumber(j);

            tmp1 = elem1;
            tmp2 = elem2->getNextLetter();

            setHead(elem2);
            elem2->setNextLetter(elem1->getNextLetter());

            previousElem2->setNextLetter(tmp1);
            tmp1->setNextLetter(tmp2);
        }
        else if(j == 0){
            elem1 = getLetterByNumber(j);
            elem2 = getLetterByNumber(i);
            previousElem2 = getPreviousLetterByNumber(i);

            tmp1 = elem1;
            tmp2 = elem2->getNextLetter();

            setHead(elem2);
            elem2->setNextLetter(elem1->getNextLetter());

            previousElem2->setNextLetter(tmp1);
            tmp1->setNextLetter(tmp2);
        }
        else{
            if(i < j){
                elem1 = getLetterByNumber(i);
                elem2 = getLetterByNumber(j);
                previousElem1 = getPreviousLetterByNumber(i);
                previousElem2 = getPreviousLetterByNumber(j);

                tmp1 = elem1;
                tmp2 = elem2->getNextLetter();

                previousElem1->setNextLetter(elem2);
                elem2->setNextLetter(tmp1->getNextLetter());

                previousElem2->setNextLetter(tmp1);
                tmp1->setNextLetter(tmp2);
            }
            else{
                elem1 = getLetterByNumber(j);
                elem2 = getLetterByNumber(i);
                previousElem1 = getPreviousLetterByNumber(j);
                previousElem2 = getPreviousLetterByNumber(i);

                tmp1 = elem1;
                tmp2 = elem2->getNextLetter();

                previousElem1->setNextLetter(elem2);
                elem2->setNextLetter(tmp1->getNextLetter());

                previousElem2->setNextLetter(tmp1);
                tmp1->setNextLetter(tmp2);
            }
        }
    }
}

void listOfLetters::setIndexes() {
    elementOfListLetters *elem = getHead();
    int i=0;
    while(elem != nullptr){
        elem->setIndex(i);
        elem = elem->getNextLetter();
        i++;
    }
}

void listOfLetters::outputIndexesInConsole() {
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        std::wcout << elem->getIndex() << ' ';
        elem = elem->getNextLetter();
    }
    std::wcout << std::endl;
}

listOfLetters::listOfLetters(listOfLetters *list) {
    elementOfListLetters *elemBase = list->getHead();
    while(elemBase != nullptr){
        auto *elemNew = new elementOfListLetters(elemBase);
        if(elemBase == list->getHead()){
            setHead(elemNew);
            setPrevious(elemNew);
        }
        else{
            getPrevious()->setNextLetter(elemNew);
            setPrevious(elemNew);
        }
        elemBase = elemBase->getNextLetter();
    }
}

bool listOfLetters::lettersDoNotNeedStamps() {
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        if(elem->getNeedToSort()){
            return false;
        }
        elem = elem->getNextLetter();
    }
    return true;
}

void listOfLetters::sortLettersByCountStamps() {
//    setIndexes();
    for(int i=0; i < getCountOfLetters()-1; i++){
        for(int j=0; j < getCountOfLetters()-1; j++){
            if(getLetterByNumber(j)->getCountOfStamps() < getLetterByNumber(j+1)->getCountOfStamps() ){
                swapLettersByNumbers(j,j+1);
            }
        }
    }
}

int listOfLetters::getMaxNeedUnits() {
    int need = -1;
    elementOfListLetters *elem = getHead();
    while(elem != nullptr){
        if(elem->getNeedUnits() > need){
            need = elem->getNeedUnits();
        }
        elem = elem->getNextLetter();
    }
    return need;
}