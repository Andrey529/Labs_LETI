#include "listOfPartsString.h"

listOfPartsString::listOfPartsString(){
    inf.setSymbol(0,'~');
    nextElementOfString = nullptr;
}

situations listOfPartsString::setInf(std::fstream &f_in){
    char s;
    int i=0;
    while (true){
        s = f_in.peek();
        if(i == (inf.getMaxLen())){
            if(s == '\n'){
                inf.setMarkInTheEnd(i);
                s = f_in.get();
                return situations::lastElement;
            }
            else if(s == -1){
                inf.setMarkInTheEnd(i);
                return situations::endOfFile;
            }
            else{
                inf.setMarkInTheEnd(i);
                return situations::notLastElement;
            }
        }
        else if(s == '\n'){
            inf.setMarkInTheEnd(i);
            s = f_in.get();
            return situations::lastElement;
        }
        else if(s == -1){
            inf.setMarkInTheEnd(i);
            return situations::endOfFile;
        }
        else{
            inf.setSymbol(i,s);
            s = f_in.get();
        }

        i++;
    }
}

void listOfPartsString::getInfInConsole(){   // output element in console
    for(int i=0; ;i++){

        if(inf.getSymbol(i) == inf.getMark()){
            break;
        }
        std::cout << inf.getSymbol(i);
    }
    std::cout << "->";
}

void listOfPartsString::getInfInFile(std::fstream &f_out){ // output element in file
    for(int i=0; ;i++){
        if(inf.getSymbol(i) == inf.getMark()){
            break;
        }
        f_out << inf.getSymbol(i);
    }
    f_out << "->";
}

listOfPartsString *listOfPartsString::getNextElement(){ // get pointer to the next element
    return nextElementOfString;
}

void listOfPartsString::setNextElement(listOfPartsString *next){ // set pointer to the next element
    nextElementOfString = next;
}

void listOfPartsString::setMaxLenOfPart(int i) {
    inf.setMaxLen(i);
}

int listOfPartsString::getMaxLenOfPart() {
    return inf.getMaxLen();
}

listOfPartsString::~listOfPartsString() {
    // auto delete inf
}

listOfPartsString::listOfPartsString(listOfPartsString &partString) {
    int i = 0;
    inf.setMark(partString.inf.getMark());
    do{
        inf.setSymbol(i,partString.inf.getSymbol(i));
        if(partString.inf.getSymbol(i) == partString.inf.getMark()){
            break;
        }
        i++;
    }
    while(true);
}

char listOfPartsString::getSymbolInfOfPartString(int i) {
    return inf.getSymbol(i);
}

char listOfPartsString::getMarkInfofPartString() {
    return inf.getMark();
}
