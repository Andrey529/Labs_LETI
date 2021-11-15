#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"

template<class T>
class iterator{
public:
    virtual T nextRight() = 0;
    virtual bool hasNextRight() = 0;
    virtual T nextLeft() = 0;
    virtual bool hasNextLeft() = 0;
};

template<class T>
class binaryTreeSearchIterator : public iterator{
private:
    elemOfBinaryTreeSearch<T> *current;
public:
    binaryTreeSearchIterator(elemOfBinaryTreeSearch<T> *start = nullptr) : current(start) {}
    ~binaryTreeSearchIterator() = default;

    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);

    T nextRight() override;
    bool hasNextRight() override;

    T nextLeft() override;
    bool hasNextLeft() override;

    create_dft_iterator(); // создание итератора, реализующего один из
                            // методов обхода в глубину (depth-first traverse)
    create_bft_iterator() // создание итератора, реализующего методы
                            // обхода в ширину (breadth-first traverse)
};

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}

template<class T>
T binaryTreeSearchIterator<T>::nextRight() {
    return nullptr;
}


#endif //LAB3_ITERATOR_H
