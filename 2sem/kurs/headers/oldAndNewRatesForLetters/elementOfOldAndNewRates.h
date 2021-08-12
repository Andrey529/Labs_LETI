#ifndef KURS_ELEMENTOFOLDANDNEWRATES_H
#define KURS_ELEMENTOFOLDANDNEWRATES_H
#include "rateValues.h"
#include "../situations.h"
#include <fstream>
#include <iostream>

class elementOfOldAndNewRates{
private:
    bool typeOfAddress = false;
    bool typeOfLetter = false;
    rateValues *valuesHead = nullptr;
    rateValues *valuePrevious = nullptr;
    elementOfOldAndNewRates *nextElement = nullptr;
public:
    void setTypeOfAddress(bool i);
    bool getTypeOfAddress() const;
    void setTypeOfLetter(bool i);
    bool getTypeOfLetter() const;
    void setNextElement(elementOfOldAndNewRates *elem);
    elementOfOldAndNewRates *getNextElement();

    void setHeadValues(rateValues *elem);
    rateValues *getHeadValues();
    void setPreviousValue(rateValues *elem);
    rateValues *getPreviousValue();

    bool listNotEmpty();

    situations inputDataOfElementOldAndNewRates(std::wfstream &f_in, std::wfstream &f_log);

    void outputInConsole();
    void outputInFile(std::wfstream &f_out, std::wfstream &f_log);

    ~elementOfOldAndNewRates();
};

#endif //KURS_ELEMENTOFOLDANDNEWRATES_H
