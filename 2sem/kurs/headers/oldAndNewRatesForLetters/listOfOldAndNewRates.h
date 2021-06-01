#ifndef KURS_LISTOFOLDANDNEWRATES_H
#define KURS_LISTOFOLDANDNEWRATES_H
#include "elementOfOldAndNewRates.h"

class listOfOldAndNewRatesForLetters{
private:
    elementOfOldAndNewRates *head = nullptr;
    elementOfOldAndNewRates *previous = nullptr;
public:
    void setHead(elementOfOldAndNewRates *elem);
    elementOfOldAndNewRates *getHead();
    void setPrevious(elementOfOldAndNewRates *elem);
    elementOfOldAndNewRates *getPrevious();

    bool listNotEmpty();

    static bool notEnoughMemory(situations situation) ;
    static bool emptyFile(situations situation);
    static bool endOfFile(situations situation);
    static bool notLastElement(situations situation);

    listOfOldAndNewRatesForLetters(std::wfstream &f_in, std::wfstream &f_log);

    void outputListOfRatesInConsoleAndInFile(std::wfstream &f_out, std::wfstream &f_log);
    void outputInConsole();
    void outputInFile(std::wfstream &f_out, std::wfstream &f_log);

    ~listOfOldAndNewRatesForLetters();
};

#endif //KURS_LISTOFOLDANDNEWRATES_H
