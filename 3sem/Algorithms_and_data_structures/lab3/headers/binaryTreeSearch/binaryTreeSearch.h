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
    ~binaryTreeSearch() = default;

    iterator<T> *create_dft_iterator(); // создание итератора, реализующего один из
    // методов обхода в глубину (depth-first traverse)
    iterator<T> *create_bft_iterator(); // создание итератора, реализующего методы
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

template<class T>
void binaryTreeSearch<T>::remove(T data) {

    // search element that need to remove
    elemOfBinaryTreeSearch<T> *delElem;
    if (isEmpty()) {
        throw std::out_of_range("Binary tree search is empty. Function remove()");
    }
    else{
        delElem = giveElemByData(data);
    }


    // removable element found
    // now start to remove
    if ( (delElem->getNextLeft() == nullptr) && (delElem->getNextRight() == nullptr) ) {
        removeWhenZeroChild(delElem);
    }
    else if ( (delElem->getNextLeft() != nullptr) && (delElem->getNextRight() == nullptr) ) {
        removeWhenOneChildLeft(delElem);
    }
    else if ( (delElem->getNextRight() != nullptr) && (delElem->getNextLeft() == nullptr) ) {
        removeWhenOneChildRight(delElem);
    }
    else {  // (delElem->getNextRight() != nullptr) && (delElem->getNextLeft() != nullptr)
        removeWhenTwoChild(delElem);
    }

}

template<class T>
void binaryTreeSearch<T>::removeWhenZeroChild(elemOfBinaryTreeSearch<T> *delElem) {
    if (delElem == this->head) {
        this->head = nullptr;
        delete delElem;
        return;
    }
    elemOfBinaryTreeSearch<T> *parent = delElem->getParent();
    if (parent->getNextLeft() == delElem) {
        parent->setNextLeft(nullptr);
    }
    else{ // parent->getNextRight() == delElem
        parent->setNextRight(nullptr);
    }
    delete delElem;
}

template<class T>
void binaryTreeSearch<T>::removeWhenOneChildLeft(elemOfBinaryTreeSearch<T> *delElem) {
    if (delElem == this->head) {
        delElem->getNextLeft()->setParent(nullptr);
        this->head = delElem->getNextLeft();
        delete delElem;
        return;
    }

    elemOfBinaryTreeSearch<T> *parent = delElem->getParent();
    elemOfBinaryTreeSearch<T> *child;

    if (delElem->getNextLeft() != nullptr) child = delElem->getNextLeft();
    else child = delElem->getNextRight();

    child->setParent(parent);
    if (parent->getNextLeft() == delElem) {
        parent->setNextLeft(child);
    }
    else if (parent->getNextRight() == delElem) {
        parent->setNextRight(child);
    }
    delete delElem;
}

template<class T>
void binaryTreeSearch<T>::removeWhenOneChildRight(elemOfBinaryTreeSearch<T> *delElem) {
    if (delElem == this->head) {
        delElem->getNextRight()->setParent(nullptr);
        this->head = delElem->getNextRight();
        delete delElem;
        return;
    }

    elemOfBinaryTreeSearch<T> *parent = delElem->getParent();
    elemOfBinaryTreeSearch<T> *child;

    if (delElem->getNextLeft() != nullptr) child = delElem->getNextLeft();
    else child = delElem->getNextRight();

    child->setParent(parent);

    if (parent->getNextLeft() == delElem) {
        parent->setNextLeft(child);
    }
    else if (parent->getNextRight() == delElem) {
        parent->setNextRight(child);
    }
    delete delElem;
}

template<class T>
void binaryTreeSearch<T>::removeWhenTwoChild(elemOfBinaryTreeSearch<T> *delElem) {
    elemOfBinaryTreeSearch<T> *theLowestElemInRightTree = delElem->getNextRight();
    // доходим до самого левого элемента в правом поддереве относительно удаляемого элемента
    while ( theLowestElemInRightTree->getNextLeft() != nullptr ) {
        theLowestElemInRightTree = theLowestElemInRightTree->getNextLeft();
    }

    // устанавливаем потомкам удаляемого элемента нового родителя
    delElem->getNextLeft()->setParent(theLowestElemInRightTree);
    if (delElem->getNextRight() != theLowestElemInRightTree)
        delElem->getNextRight()->setParent(theLowestElemInRightTree);


    // родителю самого левого элемента устанавливаем в значение, место самого левого, nullptr
    elemOfBinaryTreeSearch<T> *parentTheLowestElemInRightTree = theLowestElemInRightTree->getParent();
    if(parentTheLowestElemInRightTree->getNextLeft() == theLowestElemInRightTree) {
        parentTheLowestElemInRightTree->setNextLeft(theLowestElemInRightTree->getNextRight());
    }
    else {  // parentTheLowestElemInRightTree->getNextRight() == theLowestElemInRightTree
        parentTheLowestElemInRightTree->setNextRight(theLowestElemInRightTree->getNextRight());
    }

    // присваиваем nextLeft и nextRight самому левому значения потомков удаляемого элемента
    theLowestElemInRightTree->setNextLeft(delElem->getNextLeft());
    theLowestElemInRightTree->setNextRight(delElem->getNextRight());



    // устанавливаем родителя для нового элемента (самого левого в правом поддереве)
    if (delElem != this->head) {
        theLowestElemInRightTree->setParent(delElem->getParent());

        // присваиваем родителю удаляемого элемента вместо удаляемого элемента самый левый элемент
        elemOfBinaryTreeSearch<T> *parentDelElem = delElem->getParent();
        if(parentDelElem->getNextLeft() == delElem) {
            parentDelElem->setNextLeft(theLowestElemInRightTree);
        }
        else { // parentDelElem->getNextRight() == delElem
            parentDelElem->setNextRight(theLowestElemInRightTree);
        }

    }
    else {
        theLowestElemInRightTree->setParent(nullptr);
        this->head = theLowestElemInRightTree;
    }

    delete delElem;
}

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearch<T>::giveElemByData(T data) {
    elemOfBinaryTreeSearch<T> *delElem = this->head;
    while (true) {
        if (data == delElem->getData()) {
            return delElem;
        }
        else if ( (data < delElem->getData()) && (delElem->getNextLeft() == nullptr) ){
            throw std::out_of_range("Element with data not found. Function giveElemByData()");
        }
        else if ( (data < delElem->getData()) && (delElem->getNextLeft() != nullptr) ){
            delElem = delElem->getNextLeft();
            continue;
        }
        else if ( (data > delElem->getData()) && (delElem->getNextRight() == nullptr) ){
            throw std::out_of_range("Element with data not found. Function giveElemByData()");
        }
        else if ( (data > delElem->getData()) && (delElem->getNextRight() != nullptr) ){
            delElem = delElem->getNextRight();
            continue;
        }
    }
}

template<class T>
iterator<T> *binaryTreeSearch<T>::create_dft_iterator() {
    return new binaryTreeSearchDepthFirstTraverseIterator<T>(this->head);
}

template<class T>
iterator<T> *binaryTreeSearch<T>::create_bft_iterator() {
    return new binaryTreeSearchBreadthFirstTraverseIterator<T>(this->head);
}


#endif //LAB3_BINARYTREESEARCH_H
