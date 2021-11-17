#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H

#include "elemOfQueue.h"
#include <cstddef>
#include <stdexcept>

template<class T>
class queue{
private:
    elemOfQueue<T> *head;
public:
    queue();
    queue(elemOfQueue<T> *elemOfQueue);
    queue(T data);

    void push(elemOfQueue<T> data);
    void push();
    void pop();
    elemOfQueue<T> *getFront();
    elemOfQueue<T> *getBack();
    bool isEmpty() const;
    size_t getSize() const;
    ~queue();
};

#include "../../src/queue/queue.cpp"

#endif //LAB3_QUEUE_H
