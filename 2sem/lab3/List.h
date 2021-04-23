#ifndef LAB3_LIST_H
#define LAB3_LIST_H
#include <fstream>
#include "elementList.h"
#include "informationOfTheElement.h"
#include "situations.h"

class List{
private:
    elementList *head = nullptr;
    elementList *previous = nullptr;
    elementList *current = nullptr;
    elementList *last = nullptr;
public:
    List(std::fstream *f_in);
    bool listNotEnd(situations situations);
    bool memoryDidnotAllocate(situations situation);
    situations addNewElement(std::fstream *f_in);
    elementList *getHead();
    void outputList(std::fstream &f_out);
    situations replaceElement(std::fstream *f_replace);
};

#endif //LAB3_LIST_H


List::List(std::fstream *f_in) {
    elementList *elem = new elementList;
    if(!elem){
        std::cout << "Недостаточно памяти для 1 элемента списка." << std::endl;
        head = nullptr;
    }
    else{
        situations flag = elem->setInf(f_in);
        if(listNotEnd((flag))){
            head = elem;
            previous = elem;
        }
        else{
            head = nullptr;
        }
    }
}

situations List::addNewElement(std::fstream *f_in){
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){
        std::cout << "Недостаточно памяти для элемента списка." << std::endl;
        return situations::notEnoughMemory;
    }
    previous->setNextElement(elem);
    situations flag = elem->setInf(f_in);
    if(listNotEnd((flag))){
        previous = elem;
        return situations::notLastElement;
    }
    else{
        elem->setNextElement(nullptr);
        return situations::end;
    }
}

bool List::listNotEnd(situations situation) {
    return situation == situations::notLastElement;
}

bool List::memoryDidnotAllocate(situations situation){
    return situation == situations::notEnoughMemory;
}

elementList *List::getHead(){
    return head;
}

void List::outputList(std::fstream &f_out){
    elementList *elem = head;
    while(true){
        elem->getInfInConsole();
        elem->getInfInFile(f_out);
        if(elem->getNextElement() == nullptr) break;
        else elem = elem->getNextElement();
    }
}

situations List::replaceElement(std::fstream *f_replace){
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){
        std::cout << "Недостаточно памяти для элемента списка." << std::endl;
        return situations::notEnoughMemory;
    }

    int numberOfReplaceElement;
    *f_replace >> numberOfReplaceElement;
    char s = f_replace->get(); // разделитель между номером элемента и содержимым элемента
    elem->setInf(f_replace);
    elementList *el = head;
//    for(int i=1; i < (numberOfReplaceElement); i++){
//        el = el->getNextElement();
//    }
    elementList *tmp = el->getNextElement();  // запоминаем старый элемент
    el->setNextElement(elem);            // переназначаем следующий элемент у предыдущего на введенный
    elem->setNextElement(tmp);           // у введенного переназначенного элемента устанавливаем следующий элемент
    delete tmp;
    return situations::good;
}