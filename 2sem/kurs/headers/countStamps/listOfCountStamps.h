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

    countOfStamps(std::fstream &f_in, std::fstream &f_log);  // input all data of count stamps in list
    situations addFirstElement(std::fstream &f_in, std::fstream &f_log);
    situations addNewElement(std::fstream &f_in, std::fstream &log);

    void outputCountOfStampsInFileAndInConsole(std::fstream &f_result, std::fstream &f_log);   // output all data in list
    void outputCountOfStampsInFile(std::fstream &f_result, std::fstream &f_log);
    void outputCountOfStampsInConsole(std::fstream &f_log);
    ~countOfStamps();
};

#endif //KURS_LISTOFCOUNTSTAMPS_H