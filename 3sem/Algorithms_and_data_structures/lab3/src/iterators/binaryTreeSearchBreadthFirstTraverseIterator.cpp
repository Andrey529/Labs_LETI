#ifndef LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP
#define LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/iterators/binaryTreeSearchBreadthFirstTraverseIterator.h"

template<class T>
binaryTreeSearchBreadthFirstTraverseIterator<T>::binaryTreeSearchBreadthFirstTraverseIterator(
        elemOfBinaryTreeSearch<T> *start) {
    this->current = start;
    this->queue = new queue<T>(start->getData());
}

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchBreadthFirstTraverseIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchBreadthFirstTraverseIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}

//template<class T>
//T binaryTreeSearchBreadthFirstTraverseIterator<T>::next() {
//    if (!hasNext()) {
//        throw std::out_of_range("No more elements in binary tree search. Function next()");
//    }
//
//
//    return nullptr;
//}
//
//template<class T>
//bool binaryTreeSearchBreadthFirstTraverseIterator<T>::hasNext() {
//    return this->current != nullptr;
//}



#endif //LAB3_BINARYTREESEARCHBREADTHFIRSTTRAVERSEITERATOR_CPP
