#ifndef LAB3_LIST_H
#define LAB3_LIST_H
#include <fstream>
#include "elementList.h"
#include "situations.h"

class List{
private:
    elementList *head = nullptr;
    elementList *previous = nullptr;
public:
    situations addFirstElement(std::fstream *f_in);
    bool listNotEnd(situations situations);
    bool memoryDidnotAllocate(situations situation);
    situations addNewElement(std::fstream *f_in);
    elementList *getHead();
    void outputList(std::fstream &f_out);
    situations replaceElement(std::fstream *f_replace);
    elementList *getElemByNumber(int numberOfElement);
    elementList *getPreviousElemByNumber(int numberOfElement);
    ~List();
};


situations List::addFirstElement(std::fstream *f_in) {
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){
        std::cout << "Недостаточно памяти для 1 элемента списка." << std::endl;
        return situations::notEnoughMemory;
    }
    else{

        char s = f_in->peek();
        if(s == -1){ // файл пустой
            return situations::emptyFile;
        }
        else{
            situations flag = elem->setInf(f_in);

            if(listNotEnd((flag))){
                head = elem;
                previous = elem;
            }
            else{
                head = elem;
                return situations::inList1Element;
            }
            return situations::good;
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
    elem->getInfInConsole();
    int numberElementsInList = 0;

    // подсчет колва элементов в списке, проверить вроде криво
    {
        elementList *el = head;
        while(el != nullptr){
            el = el->getNextElement();
            numberElementsInList++;
        }
        std::cout << "In list " << numberElementsInList << " elements" << std::endl;
    }

    // фильтрация неправильного ввода номера изменяемого элемента списка
    if( (numberOfReplaceElement <= 0) || (numberOfReplaceElement > numberElementsInList) ){
        std::cout << "In input file with replacement element, number of replacement element do not true." << std::endl;
        int i = 0;
        while(true){
            std::cout << "\nInput number of replacement number:" << std::endl;
            std::cin >> numberOfReplaceElement;
            i++;
            if( (numberOfReplaceElement > 0) && (numberOfReplaceElement <= numberElementsInList) ){
                break;
            }
            else if(i >= 3){
                return situations::badNumberOfReplacementElement;
            }
        }
    }
    // замена элемента если он 1
    if(numberOfReplaceElement == 1){
        elementList *tmp = head;
        head = elem;
        elem->setNextElement(tmp->getNextElement());
        delete tmp;
    }
    else{
        // замена элемента который не 1
        {
            elementList *tmp = getElemByNumber(numberOfReplaceElement);
            previous = getPreviousElemByNumber(numberOfReplaceElement);
            previous->setNextElement(elem);
            elem->setNextElement(tmp->getNextElement());
            delete tmp;
        }
    }

    return situations::good;
}

elementList *List::getElemByNumber(int numberOfElement){
    elementList *elem = head;
    for(int i=1; i<numberOfElement; i++){
        elem = elem->getNextElement();
    }
    return elem;
}

elementList *List::getPreviousElemByNumber(int numberOfElement){
    elementList *elem = head;
    for(int i=1; i<(numberOfElement-1); i++){
        elem = elem->getNextElement();
    }
    return elem;
}

List::~List(){
    elementList *elem = head;
    elementList *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        delete tmp;
    }
}

#endif //LAB3_LIST_H
