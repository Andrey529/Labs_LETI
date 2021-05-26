#ifndef KURS_PARTOFSTRING_H
#define KURS_PARTOFSTRING_H
#include "dataOfPartString.h"
#include <fstream>
#include "../situations.h"
class partOfString{
private:
    dataOfPartString *inf = nullptr;
    partOfString *nextPartOfString = nullptr;
public:
    partOfString();
    partOfString(partOfString *elem);
    situations setInf(std::wfstream &f_in, std::wfstream &f_log, wchar_t ogranichitel);   // input information part
    void getInfInConsole();   // output element in console
    void getInfInFile(std::wfstream &f_out); // output element in file
    partOfString *getNextElement(); // get pointer to the next element
    void setNextElement(partOfString *next); // set pointer to the next element
    ~partOfString();
    void setMaxLenOfPart(int i);
    int getMaxLenOfPart();

};

#endif //KURS_PARTOFSTRING_H