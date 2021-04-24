#ifndef LAB3_INFORMATIONOFTHEELEMENT_H
#define LAB3_INFORMATIONOFTHEELEMENT_H

class informationOfElement{
private:
    char *pointerArray = nullptr;
    char Mark = '@';
public:
    void clearMemory(){
        delete[] pointerArray;
    }
    informationOfElement(){   // allocate memory for array of chars in element in list
        pointerArray = new char[11];
    }
    void allocateNewMemoryForSomeSymbols(int previousLenght, int lenght){   // allocate new memory for array of chars
        char *ptr = new char[lenght];
        for(int i=0; i<previousLenght; i++){
            *(ptr+i) = *(pointerArray+i);
        }
        delete[] pointerArray;
        pointerArray = ptr;
    }
    void setSymbol(int i, char s){
        *(pointerArray+i) = s;
    }   // set symbol in array
    char getSymbol(int i){
        return *(pointerArray+i);
    }          // get symbol of array
    void setMark(char s){
        Mark = s;
    }           // set global mark of ending arrays
    void setMark_inTheEnd(int i){
        *(pointerArray+i) = Mark;
    }  // set mark in the end of array (string)
    char getMark(){
        return Mark;
    }
};

#endif //LAB3_INFORMATIONOFTHEELEMENT_H
