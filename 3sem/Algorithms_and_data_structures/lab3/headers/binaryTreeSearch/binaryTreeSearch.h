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
    ~binaryTreeSearch() = default;


    void create_dft_iterator(); // создание итератора, реализующего один из
    // методов обхода в глубину (depth-first traverse)
    void create_bft_iterator(); // создание итератора, реализующего методы
    // обхода в ширину (breadth-first traverse)

    bool isEmpty();
    bool contains(T data); // поиск элемента в дереве по ключу
    void insert(T data); // добавление элемента в дерево по ключу. Должен работать за O(logN)
    void remove(T data); // удаление элемента дерева по ключу

};

template<class T>
bool binaryTreeSearch<T>::isEmpty() {
    return this->head == nullptr;
}

template<class T>
void binaryTreeSearch<T>::insert(T data) {
    if (isEmpty()) {
        auto *newElem = new elemOfBinaryTreeSearch<T>(data);
        this->head = newElem;
    }
    else {
        elemOfBinaryTreeSearch<T> *tempElem = this->head;
        while (true) {
            if ( (data <= tempElem->getData()) && (tempElem->getNextLeft() == nullptr) ){
                auto *newElem = new elemOfBinaryTreeSearch<T>(data,tempElem);
                tempElem->setNextLeft(newElem);
                return;
            }
            else if ( (data <= tempElem->getData()) && (tempElem->getNextLeft() != nullptr) ){
                tempElem = tempElem->getNextLeft();
                continue;
            }
            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() == nullptr) ){
                auto *newElem = new elemOfBinaryTreeSearch<T>(data,tempElem);
                tempElem->setNextRight(newElem);
                return;
            }
            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() != nullptr) ){
                tempElem = tempElem->getNextRight();
                continue;
            }
        }
    }
}

template<class T>
bool binaryTreeSearch<T>::contains(T data) {
    if (isEmpty()) {
        throw std::out_of_range("Binary tree search is empty. Function contains()");
    }
    else{
        elemOfBinaryTreeSearch<T> *tempElem = this->head;
        while (true) {
            if (data == tempElem->getData()) {
                return true;
            }
            else if ( (data < tempElem->getData()) && (tempElem->getNextLeft() == nullptr) ){
                return false;
            }
            else if ( (data < tempElem->getData()) && (tempElem->getNextLeft() != nullptr) ){
                tempElem = tempElem->getNextLeft();
                continue;
            }
            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() == nullptr) ){
                return false;
            }
            else if ( (data > tempElem->getData()) && (tempElem->getNextRight() != nullptr) ){
                tempElem = tempElem->getNextRight();
                continue;
            }
        }
    }
}


#endif //LAB3_BINARYTREESEARCH_H
