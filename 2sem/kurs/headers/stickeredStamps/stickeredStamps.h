#ifndef KURS_STICKEREDSTAMPS_H
#define KURS_STICKEREDSTAMPS_H
#include "elementOfStikeredStamps.h"
#include <fstream>
#include <iostream>

class stickekeredStamps{
private:
    elementOfStikeredStamps *head = nullptr;
    elementOfStikeredStamps *previous = nullptr;
public:
    void setHead(elementOfStikeredStamps *elem);
    elementOfStikeredStamps *getHead();
    void setPrevious(elementOfStikeredStamps *elem);
    elementOfStikeredStamps *getPrevious();
    ~stickekeredStamps();

    stickekeredStamps();
    stickekeredStamps(stickekeredStamps *list);
    void setElement(int denomination, int needUnits, int countStamps);
    void outputList(std::wfstream &f_log, std::wfstream &f_out);
    void outputListInConsole();
    void outputListInFile(std::wfstream &f_log, std::wfstream &f_out);

};

#endif //KURS_STICKEREDSTAMPS_H
