#ifndef LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H
#define LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H

#include "iterator.h"
#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"
#include "../queue/queue.h"

template<class T>
class binaryTreeSearchBreadthFirstTraverseIterator : public iterator<T>{   // методов обхода в ширину
private:
    elemOfBinaryTreeSearch<T> *current;
public:
    binaryTreeSearchBreadthFirstTraverseIterator(elemOfBinaryTreeSearch<T> *start = nullptr) : current(start) {}
    ~binaryTreeSearchBreadthFirstTraverseIterator() = default;
    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);


    T next() override;   // продумать, что именно считается следующим элементом,
                        // может понадобится хранить nextRight и nextLeft

    bool hasNext() override;   // нужно дописать нормально


};

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchBreadthFirstTraverseIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchBreadthFirstTraverseIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}

#endif //LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_H
