#ifndef KURS_PARTOFSTRING_H
#define KURS_PARTOFSTRING_H
#include "dataOfPartString.h"
#include <fstream>
#include "../situations.h"
class partOfString{
private:
    dataOfPartString *inf;
    partOfString *nextPartOfString;
public:
    partOfString();
    situations setInf(std::fstream &f_in, std::fstream &f_log);   // input information part
//    void getInfInConsole();   // output element in console
//    void getInfInFile(std::fstream &f_out); // output element in file
    partOfString *getNextElement(); // get pointer to the next element
    void setNextElement(partOfString *next); // set pointer to the next element
    ~partOfString();
//    void setMaxLenOfPart(int i);
//    int getMaxLenOfPart();
//    partOfString(partOfString &partString);   // конструктор копирования
//    char getSymbolInfOfPartString(int i);    // для сравнения массивов
//    char getMarkInfofPartString();           // для сравнения массивов

};

#endif //KURS_PARTOFSTRING_H