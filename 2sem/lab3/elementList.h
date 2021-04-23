#ifndef LAB3_ELEMENTLIST_H
#define LAB3_ELEMENTLIST_H
#include "informationOfTheElement.h"
#include <fstream>
#include "situations.h"

class elementList{
private:
    informationOfElement inf; // информационная часть
    elementList *nextElement;
    int number;
public:

    situations setInf(std::fstream *f_in){
        char s;
        int i=0;
        int lenght(11);
        while(true){
            s = f_in->get();
            if(i == (lenght-1)){
                if(s == '\n'){
                    inf.setMark_inTheEnd(i);
                    return situations::notLastElement;
                }
                else if(f_in->eof()){
                    inf.setMark_inTheEnd(i);
                    return situations::end;
                }
                else{
                    inf.allocateNewMemoryForSomeSymbols(lenght,lenght+10);
                    lenght += 10;
                    inf.setSymbol(i,s);
                }
            }
            else if(s == '\n'){
                inf.setMark_inTheEnd(i);
                return situations::notLastElement;
            }
            else if(f_in->eof()){
                inf.setMark_inTheEnd(i);
                return situations::end;
            }
            else{
                inf.setSymbol(i,s);
            }
            i++;
        }
    }
    void getInfInConsole(){
        for(int i=0; ;i++){
            std::cout << inf.getSymbol(i) << ' ';
            if(inf.getSymbol(i) == inf.getMark()){
                break;
            }
        }
        std::cout << std::endl;
    }
    void getInfInFile(std::fstream &f_out){
        for(int i=0; ;i++){
            f_out << inf.getSymbol(i) << ' ';
            if(inf.getSymbol(i) == inf.getMark()){
                break;
            }
        }
        f_out << std::endl;
    }

    elementList *getNextElement(){
        return nextElement;
    }
    void setNextElement(elementList *next){
        nextElement = next;
    }
    int getNumber(){
        return number;
    }
    void setNumber(int i){
        number = i;
    }
};

#endif //LAB3_ELEMENTLIST_H
