#ifndef KURS_LISTOFLETTERS_H
#define KURS_LISTOFLETTERS_H
#include "elementOfListLetters.h"
#include <fstream>

class listOfLetters{
private:
    elementOfListLetters *head;
    elementOfListLetters *previous;
public:
    bool listIsEmpty();
    void setHead(elementOfListLetters *elem);
    elementOfListLetters *getHead();
    void setPrevious(elementOfListLetters *elem);
    elementOfListLetters *getPrevious();

    bool listNotEmpty();

    listOfLetters();
    listOfLetters(std::wfstream &f_in, std::wfstream &f_log);


};

#endif //KURS_LISTOFLETTERS_H
