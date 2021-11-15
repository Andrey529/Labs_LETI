#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"

template<class T>
class iterator{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

template<class T>
class binaryTreeSearchIterator : public iterator<T>{
private:
    elemOfBinaryTreeSearch<T> *current;
public:
    binaryTreeSearchIterator(elemOfBinaryTreeSearch<T> *start = nullptr) : current(start) {}
    ~binaryTreeSearchIterator() = default;
    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);



//
//    T next() override;   // продумать, что именно считается следующим элементом,
//                        // может понадобится хранить nextRight и nextLeft
//
//    bool hasNext() override;   // нужно дописать нормально
//
//    void create_dft_iterator(); // создание итератора, реализующего один из
//                            // методов обхода в глубину (depth-first traverse)
//    void create_bft_iterator(); // создание итератора, реализующего методы
//                            // обхода в ширину (breadth-first traverse)

// подумать нужно ли вообще использовать наследование
};

template<class T>
elemOfBinaryTreeSearch<T> *binaryTreeSearchIterator<T>::getCurrent() const {
    return this->current;
}

template<class T>
void binaryTreeSearchIterator<T>::setCurrent(elemOfBinaryTreeSearch<T> *current) {
    this->current = current;
}



//template<class T>
//T binaryTreeSearchIterator<T>::next() {
//    if (!hasNext()) throw std::out_of_range("No more elements in binary tree search. Function next()");
//
////    T temp = this->current->getData();
////    this->current = this->current->next;
////    return temp;
//}
//
//template<class T>
//bool binaryTreeSearchIterator<T>::hasNext() {
//    return this->current != nullptr;
//}

#endif //LAB3_ITERATOR_H
