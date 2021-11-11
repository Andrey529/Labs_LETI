#ifndef LAB3_ELEMOFQUEUE_H
#define LAB3_ELEMOFQUEUE_H

template<class T>
class elemOfQueue{
private:
    T data;
    elemOfQueue *nextElem;
public:
    elemOfQueue();
    elemOfQueue(T data);
    ~elemOfQueue() = default;

    T getData() const;
    void setData(T data);

    elemOfQueue *getNextElem() const;
    void setNextElem(elemOfQueue *nextElem);

};

template<class T>
elemOfQueue<T>::elemOfQueue(T data) : data(data), nextElem(nullptr){ }

template<class T>
elemOfQueue<T>::elemOfQueue() : data(0), nextElem(nullptr) { }

template<class T>
T elemOfQueue<T>::getData() const{
    return this->data;
}

template<class T>
void elemOfQueue<T>::setData(T data) {
    this->data = data;
}

template<class T>
elemOfQueue<T> *elemOfQueue<T>::getNextElem() const {
    return this->nextElem;
}

template<class T>
void elemOfQueue<T>::setNextElem(elemOfQueue *nextElem) {
    this->nextElem = nextElem;
}


#endif //LAB3_ELEMOFQUEUE_H
