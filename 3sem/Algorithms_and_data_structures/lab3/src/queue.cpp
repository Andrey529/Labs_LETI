#include "../headers/queue.h"

template<class T>
queue<T>::queue() {
    this->head = nullptr;
}

template<class T>
queue<T>::queue(elemOfQueue<T> *elemOfQueue) {
    this->head = elemOfQueue;
}

template<class T>
queue<T>::queue(T data) {
    auto *newElem = new elemOfQueue<T>(data);
    this->head = newElem;
}

template<class T>
queue<T>::~queue() {
    elemOfQueue<T> *elem = this->head;
    elemOfQueue<T> *temp;
    while (elem != nullptr) {
        temp = elem;
        elem = elem->getNextElem();
        delete temp;
    }
}

template<class T>
bool queue<T>::isEmpty() {
    return this->head == nullptr;
}

template<class T>
void queue<T>::push(elemOfQueue<T> data) {
    auto *newElem = new elemOfQueue<T>(data);
    newElem->setNextElem(this->head);
    this->head = newElem;
}

template<class T>
void queue<T>::push() {
    auto *newElem = new elemOfQueue<T>(0);
    newElem->setNextElem(this->head);
    this->head = newElem;
}

template<class T>
void queue<T>::pop() {
    elemOfQueue<T> *elem = this->head;
    if(elem->getNextElem() == nullptr) {
        delete elem;
        this->head = nullptr;
    }
    while (elem->getNextElem()->getNextElem() != nullptr) {
        elem = elem->getNextElem();
    }
    delete elem->getNextElem();
    elem->setNextElem(nullptr);
}

template<class T>
elemOfQueue<T> *queue<T>::getFront() {
    elemOfQueue<T> *elem = this->head;
    while (elem->getNextElem() != nullptr) {
        elem = elem->getNextElem();
    }
    return elem;
}

template<class T>
elemOfQueue<T> *queue<T>::getBack() {
    return this->head;
}


