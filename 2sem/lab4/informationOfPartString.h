#ifndef LAB3_INFORMATIONOFPARTSTRING_H
#define LAB3_INFORMATIONOFPARTSTRING_H
#include <iostream>

class informationOfPartString{
private:
    char *pointerArray = nullptr;
    char mark = '@';
    int maxLen = 6;
public:
    informationOfPartString(){
        pointerArray = new char[maxLen];
    }
    void setSymbol(int i, char s){
        *(pointerArray+i) = s;
    }
    char getSymbol(int i){
        return *(pointerArray+i);
    }
    void setMarkInTheEnd(int i){
        *(pointerArray+i) = mark;
    }
    void setMark(char s){
        mark = s;
    }
    char getMark() const{
        return mark;
    }
    void setMaxLen(int i){
        if(i<=0){
            std::cout << "Сannot be set maxLen because the entered value is less than or equal to 0" << std::endl;
            return;
        }
        maxLen = i+1;
    }
    int getMaxLen() const{
        return maxLen-1;
    }
    ~informationOfPartString(){
        delete[] pointerArray;
    }
};

#endif //LAB3_INFORMATIONOFPARTSTRING_H
