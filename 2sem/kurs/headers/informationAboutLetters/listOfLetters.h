#ifndef KURS_LISTOFLETTERS_H
#define KURS_LISTOFLETTERS_H
#include "elementOfListLetters.h"
#include <fstream>

class listOfLetters{
private:
    elementOfListLetters *head = nullptr;
    elementOfListLetters *previous = nullptr;
public:
    bool listNotEmpty();
    void setHead(elementOfListLetters *elem);
    elementOfListLetters *getHead();
    void setPrevious(elementOfListLetters *elem);
    elementOfListLetters *getPrevious();

    listOfLetters(std::wfstream &f_in, std::wfstream &f_log);

    static bool notEnoughMemory(situations situation) ;
    static bool emptyFile(situations situation);
    static bool endOfFile(situations situation);
    static bool lastLetter(situations situation);
    static bool notLastLetter(situations situation);

    void outputListOfLettersInConsoleAndInFile(std::wfstream &f_out, std::wfstream &f_log);
    void outputInConsole(std::wfstream &f_log);
    void outputInFile(std::wfstream &f_out, std::wfstream &f_log);

    ~listOfLetters();
};

#endif //KURS_LISTOFLETTERS_H
