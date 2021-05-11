#ifndef KURS_ELEMENTOFLISTLETTERS_H
#define KURS_ELEMENTOFLISTLETTERS_H
#include "../listOfPartsString/partOfString.h"
class elementOfListLetters{
private:
    int typeOfLetter; // 1 - простое, 2 - заказное
    partOfString *headFIO;
    partOfString *previousFIO;
    int typeOfAddress; // 1 - по России, 2 - за границу
    partOfString *headAddress;
    partOfString *previousAddress;
    int countOfStampsInLetter;
    int weightOfLetter;

    elementOfListLetters *nextLetter;
public:
    void setTypeOfLetter(int i);
    int getTypeOfLetter() const;
    void setHeadFIO(partOfString *elem);
    partOfString *getHeadFIO();
    void setPreviousFIO(partOfString *elem);
    partOfString *getPreviousFIO();
    void setTypeOfAddress(int i);
    int getTypeOfAddress() const;
    void setHeadAddress(partOfString *elem);
    partOfString *getHeadAddress();
    void setPreviousAddress(partOfString *elem);
    partOfString *getPreviousAddress();
    void setCountOfStamps(int i);
    int getCountOfStamps() const;
    void setWeight(int i);
    int getWeight() const;

    void setNextLetter(elementOfListLetters *elem);
    elementOfListLetters *getNextLetter();

    elementOfListLetters();
    elementOfListLetters(std::wfstream &f_in, std::wfstream &f_log);
    void addFirstElementOfListLetters(std::wfstream &f_in, std::wfstream &f_log);
    void addNewElementOfListLetters(std::wfstream &f_in, std::wfstream &f_log);

};

#endif //KURS_ELEMENTOFLISTLETTERS_H
