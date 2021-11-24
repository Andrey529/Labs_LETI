#ifndef LAB3_BINARYTREESEARCH_H
#define LAB3_BINARYTREESEARCH_H

#include "elemOfBinaryTreeSearch.h"
#include "../iterators/binaryTreeSearchDepthFirstTraverseIterator.h"
#include "../iterators/binaryTreeSearchBreadthFirstTraverseIterator.h"

template<class T>
class binaryTreeSearch{
private:
    elemOfBinaryTreeSearch<T> *head;

    void removeWhenZeroChild(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenOneChildLeft(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenOneChildRight(elemOfBinaryTreeSearch<T> *delElem);
    void removeWhenTwoChild(elemOfBinaryTreeSearch<T> *delElem);
    elemOfBinaryTreeSearch<T> *giveElemByData(T data);
public:
    binaryTreeSearch(elemOfBinaryTreeSearch<T> *head = nullptr) : head(head){}
    void destroyRecursive(elemOfBinaryTreeSearch<T> *elem);
    ~binaryTreeSearch();

    iterator<elemOfBinaryTreeSearch<T>> *create_dft_iterator(); // создание итератора, реализующего один из
    // методов обхода в глубину (depth-first traverse)
    iterator<elemOfBinaryTreeSearch<T>> *create_bft_iterator(); // создание итератора, реализующего методы
    // обхода в ширину (breadth-first traverse)

    bool isEmpty();
    bool contains(T data); // поиск элемента в дереве по ключу
    void insert(T data); // добавление элемента в дерево по ключу. Должен работать за O(logN)
    void remove(T data); // удаление элемента дерева по ключу

};

#include "../../src/binaryTreeSearch/binaryTreeSearch.cpp"


#endif //LAB3_BINARYTREESEARCH_H
