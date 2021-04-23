#ifndef LAB3_INFORMATIONOFTHEELEMENT_H
#define LAB3_INFORMATIONOFTHEELEMENT_H

class informationOfElement{
private:
    char *pointerArray = nullptr;
    char Mark = '@';
public:
    informationOfElement(){
        pointerArray = new char[11];
    }

    void allocateNewMemoryForSomeSymbols(int previousLenght, int lenght){
        char *ptr = new char[lenght];
        for(int i=0; i<previousLenght; i++){
            *(ptr+i) = *(pointerArray+i);
        }
        delete pointerArray;
        pointerArray = ptr;
    }

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

#endif //LAB3_INFORMATIONOFTHEELEMENT_H
