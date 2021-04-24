#ifndef LAB3_ELEMENTLIST_H
#define LAB3_ELEMENTLIST_H
#include "informationOfTheElement.h"
#include <fstream>
#include "situations.h"

class elementList{
private:
    informationOfElement inf; // contetnt of the element
    elementList *nextElement; // pointer to the next element of the list
public:
    void clearMemory(){
        inf.clearMemory();
    }
    elementList(){
        inf.setSymbol(0,'~');
        nextElement = nullptr;
    }

    situations setInf(std::fstream *f_in){    // input content from file in element of list
        char s;
        int i=0;
        int lenght(11); // lenght of content part in element
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
                else{   // if does not enough memory for content part in element
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
    }     // set content on element of list
    void getInfInConsole(){   // output element in console
        for(int i=0; ;i++){
            if(inf.getSymbol(i) == inf.getMark()){
                break;
            }
            std::cout << inf.getSymbol(i);
        }
    }                    // output content of element in console
    void getInfInFile(std::fstream &f_out){ // output element in file
        for(int i=0; ;i++){
            if(inf.getSymbol(i) == inf.getMark()){
                break;
            }
            f_out << inf.getSymbol(i);
        }
    }    // output content of element in file

    elementList *getNextElement(){ // get pointer to the next element
        return nextElement;
    }             // get pointer on next element
    void setNextElement(elementList *next){ // set pointer to the next element
        nextElement = next;
    }    // set pointer in this element to the next element
};
#endif //LAB3_ELEMENTLIST_H
