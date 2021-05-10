#ifndef KURS_ELEMENTOFLISTLETTERS_H
#define KURS_ELEMENTOFLISTLETTERS_H
#include "../listOfPartsString/partOfString.h"
class elementOfListLetters{
private:
    int typeOfLetter; // 1 - простое, 2 - заказное
    partOfString *headFIO;
    int typeOfAddress; // 1 - по России, 2 - за границу
    partOfString *headAddress;
    int countOfStampsInLetter;
    int weughtOfLetter;

    elementOfListLetters *nextLetter;
public:
    elementOfListLetters();
    elementOfListLetters(std::fstream &f_in, std::fstream &f_log);

};

#endif //KURS_ELEMENTOFLISTLETTERS_H
