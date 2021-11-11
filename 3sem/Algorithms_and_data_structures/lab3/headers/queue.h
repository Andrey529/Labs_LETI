#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H

#include "elemOfQueue.h"
#include <iostream>
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
    bool isEmpty();

//    friend std::ostream& operator<< <T>(std::ostream &out, const queue &rhs);

    friend  std::ostream& operator << (std::ostream &out, const queue<T> &queue);

    ~queue();
};

template<class T>
std::ostream& operator << (std::ostream &out, const queue<T> &queue) {

    out << "Queue:" << std::endl;
    int i = 1;

    elemOfQueue<T> *elem = queue.getFront();

    while (elem != nullptr) {
        out << i << " element of queue: data = " << elem->getData() << std::endl;
        i++;
    }

    return out;
}



#endif //LAB3_QUEUE_H
