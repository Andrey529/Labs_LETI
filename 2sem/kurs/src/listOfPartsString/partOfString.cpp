#include "../../headers/listOfPartsString/partOfString.h"

partOfString::partOfString() {
    this->inf = nullptr;
    this->nextPartOfString = nullptr;
}

situations partOfString::setInf(std::wfstream &f_in, std::wfstream &f_log) {
    wchar_t s;
    int i=0;
    this->inf = new dataOfPartString;
    while (true){
        s = f_in.peek();
        if(i == (this->inf->getMaxLen())){
            if(s == '\n'){
                this->inf->setMarkInTheEnd(i);
                s = f_in.get();
                return situations::lastElement;
            }
            else if(s == -1){
                this->inf->setMarkInTheEnd(i);
                return situations::endOfFile;
            }
            else{
                this->inf->setMarkInTheEnd(i);
                return situations::notLastElement;
            }
        }
        else if(s == '\n'){
            this->inf->setMarkInTheEnd(i);
            s = f_in.get();
            return situations::lastElement;
        }
        else if(s == -1){
            this->inf->setMarkInTheEnd(i);
            return situations::endOfFile;
        }
        else{
            this->inf->setSymbol(i,s);
            s = f_in.get();
        }
        i++;
    }
}

partOfString::~partOfString() {
    delete this->inf;
}

partOfString *partOfString::getNextElement() {
    return this->nextPartOfString;
}

void partOfString::setNextElement(partOfString *next) {
    this->nextPartOfString = next;
}

void partOfString::getInfInConsole() {
    for(int i=0; ;i++){

        if(inf->getSymbol(i) == inf->getMark()){
            break;
        }
        std::wcout << inf->getSymbol(i);
    }
    std::wcout << "->";
}
