#ifndef KURS_DATAOFPARTSTRING_H
#define KURS_DATAOFPARTSTRING_H
#include <iostream>

class dataOfPartString{
private:
    wchar_t *pointerArray = nullptr;
    wchar_t mark = '@';
    int maxLen = 6;
public:
    dataOfPartString();
    void setSymbol(int i, wchar_t s);
    wchar_t getSymbol(int i);
    void setMarkInTheEnd(int i);
    void setMark(wchar_t s);
    wchar_t getMark() const;
    void setMaxLen(int i);
    int getMaxLen() const;
    ~dataOfPartString();
};

#endif //KURS_DATAOFPARTSTRING_H
