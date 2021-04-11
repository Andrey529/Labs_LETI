#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

class informationOfElement{
private:
    char *pointerArray = nullptr;
    char Mark = '@';
public:
    void setSymbol(int i, char s){
        *(pointerArray+i) = s;
    }
    char getSymbol(int i){
        return *(pointerArray+i);
    }
    void setMark(char s){
        Mark = s;
    }
    void setMark_inTheEnd(int i){
        *(pointerArray+i) = Mark;
    }
    char getMark(){
        return Mark;
    }
};

class elementList{
private:
    informationOfElement inf; // информационная часть
    elementList *nextElement;
public:


    elementList(){
        nextElement = nullptr;
    }
    elementList* getNextElement(){
        return nextElement;
    }
    void setNextElement(elementList *next){
        nextElement = next;
    }








};

#endif //LAB3_HEADER_H