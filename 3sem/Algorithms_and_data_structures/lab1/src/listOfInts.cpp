#include "../headers/listOfInts.h"

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

size_t listOfInts::get_size() const{
    data *elem = this->head;
    int sizeList = 0;
    while(elem != nullptr){
        sizeList++;
        elem = elem->getNextElem();
    }
    return sizeList;
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

    if(index == 0){
        newElem->setNextElem(this->head);
        this->head = newElem;
        return;
    }

    if(index+1 > get_size()){
         std::cout << "In function insert index > size list " << std::endl;
        return;
    }

    data *elem = this->head;
    for(int i = 0; i < index-1; i++){
        elem = elem->getNextElem();
    }

    newElem->setNextElem(elem->getNextElem());
    elem->setNextElem(newElem);

}


void listOfInts::remove(size_t index) {
    if(this->head == nullptr){
        return;
    }

    if(index+1 > get_size()){
        std::cout << "In function remove index > size list " << std::endl;
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





