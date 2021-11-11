#include "../headers/elemOfQueue.h"

template<class T>
elemOfQueue<T>::elemOfQueue(T data) : data(data), nextElem(nullptr){ }

template<class T>
elemOfQueue<T>::elemOfQueue() : data(0), nextElem(nullptr) { }

template<class T>
T elemOfQueue<T>::getData() const{
    return this->data;
}

template<class T>
void elemOfQueue<T>::setData(const T _data) {
    this->data = _data;
}

template<class T>
elemOfQueue<T> *elemOfQueue<T>::getNextElem() const {
    return this->nextElem;
}

template<class T>
void elemOfQueue<T>::setNextElem(const elemOfQueue *_nextElem) {
    this->nextElem = _nextElem;
}


