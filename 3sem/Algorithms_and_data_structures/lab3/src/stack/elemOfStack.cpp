#ifndef LAB3_ELEMOFSTACK_CPP
#define LAB3_ELEMOFSTACK_CPP


#include "../../headers/stack/elemOfStack.h"


template<class T>
elemOfStack<T>::elemOfStack() : data(0), nextElem(nullptr) { }

template<class T>
elemOfStack<T>::elemOfStack(T data) : data(data), nextElem(nullptr) { }

template<class T>
T elemOfStack<T>::getData() const {
    return this->data;
}

template<class T>
void elemOfStack<T>::setData(T data) {
    this->data = data;
}

template<class T>
elemOfStack<T> *elemOfStack<T>::getNextElem() const {
    return this->nextElem;
}

template<class T>
void elemOfStack<T>::setNextElem(elemOfStack *nextElem) {
    this->nextElem = nextElem;
}

#endif //LAB3_ELEMOFSTACK_H
