#ifndef KURS_LISTOFCOUNTSTAMPS_H
#define KURS_LISTOFCOUNTSTAMPS_H
#include <fstream>
#include <iostream>
#include "elemListOfCountStamps.h"
#include "../situations.h"

class countOfStamps{
private:
    elemListCountOfStamps *head = nullptr;
    elemListCountOfStamps *previous = nullptr;
public:
    bool listIsEmpty(); // if list is empty (head == nullptr) return 1, else return 0
    void setHead(elemListCountOfStamps *elem);
    elemListCountOfStamps *getHead();
    void setPrevious(elemListCountOfStamps *prev);
    elemListCountOfStamps *getPrevious();

    countOfStamps(std::wfstream &f_in, std::wfstream &f_log);  // input all data of count stamps in list
    countOfStamps(countOfStamps *list);
    situations addFirstElement(std::wfstream &f_in, std::wfstream &f_log);
    situations addNewElement(std::wfstream &f_in, std::wfstream &log);

    void outputCountOfStampsInFileAndInConsole(std::wfstream &f_result, std::wfstream &f_log);   // output all data in list
    void outputCountOfStampsInFile(std::wfstream &f_result, std::wfstream &f_log);
    void outputCountOfStampsInConsole(std::wfstream &f_log);
    ~countOfStamps();

    bool haveStamps();
    int getStampOfMaxDenomination(int ogranichitel);
};

#endif //KURS_LISTOFCOUNTSTAMPS_H