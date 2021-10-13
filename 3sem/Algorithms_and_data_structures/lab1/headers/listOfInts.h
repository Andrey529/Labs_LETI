#ifndef LAB1_LISTOFINTS_H
#define LAB1_LISTOFINTS_H

#include "data.h"
#include <cstddef>
#include "situations.h"
#include "iostream"

class listOfInts {
private:
    data *head;
public:
    listOfInts(data *elem = nullptr);
    ~listOfInts();

    data *getHead() const;
    void setHead(data *elem);

    bool isEmpty(); // checking if the list is empty

    void push_back(int number); //adding new element in the end of the list
    void push_front(int number); //adding new element in the begin of the list
    void pop_back(); // deleting last element in the list
    void pop_front(); // deleting first element in the list
    void insert(int number, size_t index); // adding an element at index
                            // (insertion before an item that was previously accessible at that index)

    int at(size_t index); // getting an element data at the index

    void remove(size_t index); // deleting an element by index
    size_t get_size() const; // getting list size
    void clear(); // removing all list elements
    void set(size_t index, int number); // замена элемента по индексу на передаваемый элемент
                            // replacing the element by index with the passed element


    friend std::ostream& operator<< (std::ostream &out, const listOfInts &list); // Перегрузка оператора вывода <<

    void reverse(); // reverses the order of the elements in the list
};


listOfInts::listOfInts(data *elem) {
    if(elem == nullptr){
        this->head = nullptr;
        return;
    }

    auto *newElem = new data(elem->getNumber(), elem->getNextElem());
}

listOfInts::~listOfInts() {
    data *elem = this->head;
    data *tempElem;
    while(elem != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
        delete tempElem;
    }
}

data *listOfInts::getHead() const{
    return this->head;
}

void listOfInts::setHead(data *elem) {
    this->head = elem;
}

bool listOfInts::isEmpty() {
    return head == nullptr;
}

void listOfInts::push_back(int number) {

    auto *newElem = new data(number);

    data *elem = this->head;
    if(elem == nullptr){
        this->head = newElem;
        return;
    }

    while(elem->getNextElem() != nullptr){
        elem = elem->getNextElem();
    }

    elem->setNextElem(newElem);
}

void listOfInts::push_front(int number) {
    auto *newElem = new data(number);

    data *elem = this->head;
    if(elem == nullptr){
        this->head = newElem;
    }

    this->head = newElem;
    newElem->setNextElem(elem);

}

void listOfInts::pop_back() {
    if(this->head == nullptr){
        return;
    }
    data *elem = this->head;
    data *tempElem;
    while(elem->getNextElem() != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
    }
    delete elem;
    tempElem->setNextElem(nullptr);
}

void listOfInts::pop_front() {
    if(this->head == nullptr){
        return;
    }
    data *elem = this->head;
    this->head = this->head->getNextElem();
    delete elem;
}

void listOfInts::insert(int number, size_t index) {

    data *newElem = new data(number);

    if(this->head == nullptr){
        this->head = newElem;
        return;
    }

    try {
        if (index + 1 > get_size()) {
            throw std::invalid_argument("Index greater than size of array in function insert()");
        }
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return;
    }


    if(index == 0){
        newElem->setNextElem(this->head);
        this->head = newElem;
        return;
    }


    data *elem = this->head;
    for(int i = 0; i < index-1; i++){
        elem = elem->getNextElem();
    }

    newElem->setNextElem(elem->getNextElem());
    elem->setNextElem(newElem);

}

int listOfInts::at(size_t index) {
    data *elem = this->head;

    try {
        if (index + 1 > get_size()) {
            throw std::invalid_argument("Index greater than size of array in function at()");
        }
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    int i = 0;
    while(i != index){
        elem = elem->getNextElem();
        i++;
    }
    return elem->getNumber();
}


void listOfInts::remove(size_t index) {
    if(this->head == nullptr){
        return;
    }

    try {
        if (index + 1 > get_size()) {
            throw std::invalid_argument("Index greater than size of array in function remove()");
        }
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    data *elem = this->head;

    if(index == 0){
        this->head = this->head->getNextElem();
        delete elem;
        return;
    }

    for(int i = 0; i < index-1; i++){
        elem = elem->getNextElem();
    }

    data *delElem = elem->getNextElem();
    elem->setNextElem(delElem->getNextElem());
    delete delElem;
}

size_t listOfInts::get_size() const{
    data *elem = this->head;
    int sizeList = 0;
    while(elem != nullptr){
        sizeList++;
        elem = elem->getNextElem();
    }
    return sizeList;
}

void listOfInts::clear() {
    data *elem = this->head;
    data *tempElem;
    while(elem != nullptr){
        tempElem = elem;
        elem = elem->getNextElem();
        delete tempElem;
    }
}

std::ostream &operator<<(std::ostream &out, const listOfInts &list) {

    out << "List of integers:" << std::endl;
    data *elem = list.getHead();
    int i = 1;
    while(elem != nullptr){
        out << i << " element: number = " << elem->getNumber() << std::endl;
        i++;
        elem = elem->getNextElem();
    }

    return out;
}



void listOfInts::reverse() {

}




#endif //LAB1_LISTOFINTS_H
