#ifndef LAB3_BINARYTREESEARCH_H
#define LAB3_BINARYTREESEARCH_H

#include "elemOfBinaryTreeSearch.h"
#include "../iterator/iterator.h"

template<class T>
class binaryTreeSearch{
private:
    elemOfBinaryTreeSearch<T> *head;
public:
    binaryTreeSearch(elemOfBinaryTreeSearch<T> *head = nullptr) : head(head){}
    ~binaryTreeSearch();

    iterator<T> *createIterator();
};

template<class T>
iterator<T> *binaryTreeSearch<T>::createIterator() {
    return new binaryTreeSearchIterator(this->head);
}

#endif //LAB3_BINARYTREESEARCH_H
