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
    situations addFirstElement(std::fstream *f_in);      // add first element in list
    bool listNotEnd(situations situations);              // if list does not end
    bool memoryDidnotAllocate(situations situation);     // if memory didnot allocate
    situations addNewElement(std::fstream *f_in);        // add new elements in list
    elementList *getHead();                              // return the pointer on head element in list
    void setHead(elementList *elem);                     // set pointer on head element
    void outputList(std::fstream &f_out);                // output list
    void setPrevious(elementList *elem);                 // set pointer on previous element
    situations replaceElement(std::fstream *f_replace);  // replace element by number
    elementList *getElemByNumber(int numberOfElement);   // get pointer on element by number
    elementList *getPreviousElemByNumber(int numberOfElement);  // get pointer on previous element by number
    int countOfElementsInList();                         // counting the number of elements in the list
    ~List();                                             // delete all list
};


situations List::addFirstElement(std::fstream *f_in) {
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){           // if elem == nullptr
        std::cout << "Does not enough memory for first element in list." << std::endl;
        return situations::notEnoughMemory;
    }
    else{

        char s = f_in->peek();
        if(s == -1){ // if file with text is empty
            return situations::emptyFile;
        }
        else{
            situations flag = elem->setInf(f_in);  // input element from file

            if(listNotEnd((flag))){   // if it is not last element
                setHead(elem);
                setPrevious(elem);
            }
            else{           // if it is the last element
                setHead(elem);
                return situations::inList1Element;
            }
            return situations::good;
        }
    }
}

situations List::addNewElement(std::fstream *f_in){
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){      // if elem == nullptr
        std::cout << "Does not enough memory for element in list." << std::endl;
        return situations::notEnoughMemory;
    }
    previous->setNextElement(elem);
    situations flag = elem->setInf(f_in);
    if(listNotEnd((flag))){   // if it is not the last element
        setPrevious(elem);
        return situations::notLastElement;
    }
    else{    // if it is the last element
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

void List::setHead(elementList *elem){
    head = elem;
}

void List::setPrevious(elementList *elem){
    previous = elem;
}

void List::outputList(std::fstream &f_out){
    elementList *elem = head;
    while(true){
        elem->getInfInConsole();
        elem->getInfInFile(f_out);
        if(elem->getNextElement() == nullptr){
            std::cout << "->X" << std::endl;
            f_out << "->X" << std::endl;
            break;
        }
        else{
            elem = elem->getNextElement();
            std::cout << "->" << std::endl;
            f_out << "->" << std::endl;
        }
    }
}

situations List::replaceElement(std::fstream *f_replace){
    elementList *elem = new (std::nothrow) elementList;
    if(!elem){
        std::cout << "Does not enough memory for element in list." << std::endl;
        return situations::notEnoughMemory;
    }

    int numberOfReplaceElement;
    *f_replace >> numberOfReplaceElement;
    char s = f_replace->get(); // separator between element number and element content
    elem->setInf(f_replace);
//    elem->getInfInConsole();
    int numberElementsInList = countOfElementsInList();


    // filtering the wrong entry of the number of the list item being changed
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
    // replace element after 1 element
    if(numberOfReplaceElement == 1){
        elementList *tmp = getHead();
        setHead(elem);
        elem->setNextElement(tmp->getNextElement());
        tmp->clearMemory();
        delete tmp;
    }
    else{
        // replace element by number 1
        {
            elementList *tmp = getElemByNumber(numberOfReplaceElement);
            setPrevious(getPreviousElemByNumber(numberOfReplaceElement));
            previous->setNextElement(elem);
            elem->setNextElement(tmp->getNextElement());
            tmp->clearMemory();
            delete tmp;
        }
    }

    return situations::good;
}

elementList *List::getElemByNumber(int numberOfElement){
    elementList *elem = getHead();
    for(int i=1; i<numberOfElement; i++){
        elem = elem->getNextElement();
    }
    return elem;
}

elementList *List::getPreviousElemByNumber(int numberOfElement){
    elementList *elem = getHead();
    for(int i=1; i<(numberOfElement-1); i++){
        elem = elem->getNextElement();
    }
    return elem;
}

int List::countOfElementsInList(){
    elementList *el = getHead();
    int numberElementsInList = 0;
    while(el != nullptr){
        el = el->getNextElement();
        numberElementsInList++;
    }
    //        std::cout << "In list " << numberElementsInList << " elements" << std::endl;
    return numberElementsInList;
}

List::~List(){
    elementList *elem = getHead();
    elementList *tmp;
    while(elem != nullptr){
        tmp = elem;
        elem = elem->getNextElement();
        tmp->clearMemory();
        delete tmp;
    }
}

#endif //LAB3_LIST_H
