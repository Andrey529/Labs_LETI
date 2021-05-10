#ifndef KURS_LISTOFCOUNTSTAMPS_H
#define KURS_LISTOFCOUNTSTAMPS_H
#include <fstream>
#include <iostream>
#include "elemListOfCountStamps.h"
#include "situations.h"

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

    countOfStamps(std::fstream &f_in);  // input all data of count stamps in list
    situations addFirstElement(std::fstream &f_in);
    situations addNewElement(std::fstream &f_in);

    void outputCountOfStamps();   // output all data in list
};

#endif //KURS_LISTOFCOUNTSTAMPS_H