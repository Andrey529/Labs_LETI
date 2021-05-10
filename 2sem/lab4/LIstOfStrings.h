#ifndef LAB3_LISTOFSTRINGS_H
#define LAB3_LISTOFSTRINGS_H
#include <fstream>
#include "elementOfStringList.h"

class ListOfStrings{
private:
    elementOfStringList *head = nullptr;
    elementOfStringList *previous = nullptr;
public:
    ListOfStrings();
    explicit ListOfStrings(std::fstream &f_in);
    ListOfStrings(ListOfStrings &list);
    void setHead(elementOfStringList *head);
    elementOfStringList *getHead();
    void setPrevious(elementOfStringList *previous);
    elementOfStringList *getPrevious();
    situations addFirstElement(std::fstream &f_in);
    situations addNewElement(std::fstream &f_in);
    bool listNotEmpty();
    static bool notEnoughMemory(situations situation);
    static bool emptyFile(situations situation);
    static bool endOfFile(situations situation);
    static bool lastElement(situations situation);

    void outputListInConsole();
    void outputListInFile(std::fstream &f_out);
    void outputListInConsoleAndInFile(std::fstream &f_out);

    static ListOfStrings differenceList1AndList2(ListOfStrings& list1, ListOfStrings& list2);

    ~ListOfStrings();
};

#endif //LAB3_LISTOFSTRINGS_H
