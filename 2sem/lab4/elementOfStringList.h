#ifndef LAB3_ELEMENTOFSTRINGLIST_H
#define LAB3_ELEMENTOFSTRINGLIST_H
#include <fstream>
#include "listOfPartsString.h"

class elementOfStringList{
private:
    listOfPartsString *headToListOfPatrsString;
    listOfPartsString *previousPartString;
    elementOfStringList *nextString;
public:
    elementOfStringList();
    elementOfStringList(listOfPartsString *head, listOfPartsString *previous, elementOfStringList *next);
    void setHead(listOfPartsString *head);
    listOfPartsString *getHead();
    void setNextElement(elementOfStringList *next);
    elementOfStringList *getNextElement();
    void setPrevious(listOfPartsString *previous);
    listOfPartsString *getPrevious();
    bool listNotEnd(situations situation);
    bool endOfFile(situations situation);
    bool lastElement(situations situation);
    situations inputString(std::fstream &f_in);
    situations addFirstPartOfString(std::fstream &f_in);
    situations addNewPartOfString(std::fstream &f_in);
};



#endif //LAB3_ELEMENTOFSTRINGLIST_H
