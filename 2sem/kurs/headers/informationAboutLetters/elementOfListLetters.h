#ifndef KURS_ELEMENTOFLISTLETTERS_H
#define KURS_ELEMENTOFLISTLETTERS_H
#include "../listOfPartsString/partOfString.h"
class elementOfListLetters{
private:
    bool typeOfLetter = false; // 0 - простое, 1 - заказное
    partOfString *headFIO = nullptr;
    partOfString *previousFIO = nullptr;
    bool typeOfAddress = false; // 0 - по России, 1 - за границу
    partOfString *headAddress = nullptr;
    partOfString *previousAddress = nullptr;
    int countOfStampsInLetter = -1;
    int weightOfLetter = -1;

    int oldPrice = -1;
    int newPrice = -1;
    int needUnits = -1;

    bool needToSort = true;

    int index = -1;

    int needStamps = 0;

    elementOfListLetters *nextLetter = nullptr;
public:
    void setTypeOfLetter(bool i);             //
    bool getTypeOfLetter() const;             //
    void setHeadFIO(partOfString *elem);      //
    partOfString *getHeadFIO();               //
    void setPreviousFIO(partOfString *elem);  //
    partOfString *getPreviousFIO();           //
    void setTypeOfAddress(bool i);             //
    bool getTypeOfAddress() const;             //
    void setHeadAddress(partOfString *elem);  //
    partOfString *getHeadAddress();           //
    void setPreviousAddress(partOfString *elem); //
    partOfString *getPreviousAddress();       //
    void setCountOfStamps(int i);             //
    int getCountOfStamps() const;             //
    void setWeight(int i);                    //
    int getWeight() const;                    //

    void setOldPrice(int i);
    int getOldPrice() const;
    void setNewPrice(int i);
    int getNewPrice() const;
    void setNeedUnits(int i);
    int getNeedUnits() const;

    void setNeedToSort(bool i);
    bool  getNeedToSort() const;

    void setIndex(int i);
    int getIndex() const;

    void setNeedStamps(int i);
    int getNeedStamps() const;

    void setNextLetter(elementOfListLetters *elem);  //
    elementOfListLetters *getNextLetter();           //

    static bool NotLastElement(situations situation);    //
    static bool endOfFile(situations situation);     //
    static bool lastElement(situations situation);   //
    static bool notEnoughMemory(situations situation); //
    static bool emptyFile(situations situation);     //
    static bool listNotEmpty(partOfString *head);    //

    elementOfListLetters();                          //
    elementOfListLetters(elementOfListLetters *elem);
    situations inputDataOfElementOfListLetters(std::wfstream &f_in, std::wfstream &f_log);

    situations inputFIO(std::wfstream &f_in, std::wfstream &f_log, wchar_t ogranichitel);
    situations inputAddress(std::wfstream &f_in, std::wfstream &f_log, wchar_t ogranichitel);

    void outputDataOfElementOfListLettersInConsole(std::wfstream &f_log);
    void outputDataOfElementOfListLettersInFile(std::wfstream &f_out, std::wfstream &f_log);

    ~elementOfListLetters();
};

#endif //KURS_ELEMENTOFLISTLETTERS_H
