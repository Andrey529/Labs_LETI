#ifndef LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP
#define LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP

#include "../../headers/iterators/binaryTreeSearchDepthFirstTraverseIterator.h"

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchDepthFirstTraverseIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchDepthFirstTraverseIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}


#endif //LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_CPP
