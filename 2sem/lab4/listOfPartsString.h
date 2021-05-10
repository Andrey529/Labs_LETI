#ifndef LAB3_LISTOFPARTSSTRING_H
#define LAB3_LISTOFPARTSSTRING_H
#include <fstream>
#include "situations.h"
#include "informationOfPartString.h"

class listOfPartsString{
private:
    informationOfPartString inf;
    listOfPartsString *nextElementOfString;
public:
    listOfPartsString();
    listOfPartsString(listOfPartsString &partString);
    situations setInf(std::fstream &f_in);   // input information part
    void getInfInConsole();   // output element in console
    void getInfInFile(std::fstream &f_out); // output element in file
    listOfPartsString *getNextElement(); // get pointer to the next element
    void setNextElement(listOfPartsString *next); // set pointer to the next element
//    void clearMemory();  // clear memory of information part
    void setMaxLenOfPart(int i);
    int getMaxLenOfPart();
    ~listOfPartsString();
    char getSymbolInfOfPartString(int i);
    char getMarkInfofPartString();

};


#endif //LAB3_LISTOFPARTSSTRING_H
