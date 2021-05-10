#ifndef KURS_DATAOFPARTSTRING_H
#define KURS_DATAOFPARTSTRING_H
#include <iostream>

class dataOfPartString{
private:
    char *pointerArray = nullptr;
    char mark = '@';
    int maxLen = 6;
public:
    dataOfPartString();
    void setSymbol(int i, char s);
    char getSymbol(int i);
    void setMarkInTheEnd(int i);
    void setMark(char s);
    char getMark() const;
    void setMaxLen(int i);
    int getMaxLen() const;
    ~dataOfPartString();
};

#endif //KURS_DATAOFPARTSTRING_H
