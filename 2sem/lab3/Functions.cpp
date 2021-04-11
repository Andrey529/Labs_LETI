#include "header.h"
#include <fstream>

void newElement(elementList **pointer){
    *pointer = new elementList;

}
void addNextElement(){
    elementList *pointer;
    newElement(&pointer);
}

void addFirstElement(){
    elementList *pointer;
    newElement(&pointer);
    initFirstElement();
}

bool notEmptyPointer(elementList *pointer) {
    return pointer != nullptr;
}



void inputList(std::fstream &f_in, elementList **head){
    *head = nullptr;
    while(!f_in.eof()){
        if(notEmptyPointer(*head)){
            addNextElement();
        }
        else{
            addFirstElement();
        }
    }
}


//void DeleteAllList(elementList **head){  // удаление всего списка
//    elementList *current; // вспомогательный указатель
//    while(*head != nullptr){
//        current = (*head)->getNextElement();
//        delete *head;
//        *head = current;
//    }
//}

