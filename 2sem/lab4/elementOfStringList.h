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
    elementOfStringList(elementOfStringList &string);
    void setHead(listOfPartsString *head);
    listOfPartsString *getHead();
    void setNextElement(elementOfStringList *next);
    elementOfStringList *getNextElement();
    void setPrevious(listOfPartsString *previous);
    listOfPartsString *getPrevious();
    static bool listNotEnd(situations situation);
    static bool endOfFile(situations situation);
    static bool lastElement(situations situation);
    static bool notEnoughMemory(situations situation);
    static bool emptyFile(situations situation);
    bool listNotEmpty();
    situations inputString(std::fstream &f_in);
    situations addFirstPartOfString(std::fstream &f_in);
    situations addNewPartOfString(std::fstream &f_in);

    void outputStringInConsole();
    void outputStringInFile(std::fstream &f_out);

    ~elementOfStringList();
};

#endif //LAB3_ELEMENTOFSTRINGLIST_H
