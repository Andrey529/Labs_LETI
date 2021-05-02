#ifndef LAB3_LISTOFSTRINGS_H
#define LAB3_LISTOFSTRINGS_H
#include <fstream>
#include "elementOfStringList.h"

class ListOfStrings{
private:
    elementOfStringList *head;
    elementOfStringList *previous;
public:
    ListOfStrings();
    ListOfStrings(elementOfStringList *head, elementOfStringList *previous);
    void setHead(elementOfStringList *head);
    elementOfStringList *getHead();
    void setPrevious(elementOfStringList *previous);
    elementOfStringList *getPrevious();
    situations addFirstElement(std::fstream &f_in);
    situations addNewElement(std::fstream &f_in);
    situations inputList(std::fstream &f_in);
};




#endif //LAB3_LISTOFSTRINGS_H
