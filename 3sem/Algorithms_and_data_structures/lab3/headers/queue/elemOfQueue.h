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

#include "../../src/queue/elemOfQueue.cpp"

#endif //LAB3_ELEMOFQUEUE_H
