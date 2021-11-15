#ifndef LAB3_ELEMOFBINARYTREESEARCH_H
#define LAB3_ELEMOFBINARYTREESEARCH_H

template<class T>
class elemOfBinaryTreeSearch{
private:
    T data;
    elemOfBinaryTreeSearch *parent;
    elemOfBinaryTreeSearch *nextLeft;
    elemOfBinaryTreeSearch *nextRight;
public:
    elemOfBinaryTreeSearch(T data = 0, elemOfBinaryTreeSearch *parent = nullptr,
                           elemOfBinaryTreeSearch *nextLeft = nullptr, elemOfBinaryTreeSearch *nextRight = nullptr)
                           : data(data), parent(parent), nextLeft(nextLeft), nextRight(nextRight) {}
    ~elemOfBinaryTreeSearch() = default;

    T getData() const;
    void setData(T data);

    elemOfBinaryTreeSearch *getParent() const;
    void setParent(elemOfBinaryTreeSearch *parent);

    elemOfBinaryTreeSearch *getNextLeft() const;
    void setNextLeft(elemOfBinaryTreeSearch *nextLeft);

    elemOfBinaryTreeSearch *getNextRight() const;
    void setNextRight(elemOfBinaryTreeSearch *nextRight);

};

template<class T>
T elemOfBinaryTreeSearch<T>::getData() const {
    return this->data;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setData(T data) {
    this->data = data;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getParent() const {
    return this->parent;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setParent(elemOfBinaryTreeSearch *parent) {
    this->parent = parent;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getNextLeft() const {
    return this->nextLeft;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setNextLeft(elemOfBinaryTreeSearch *nextLeft) {
    this->nextLeft = nextLeft;
}

template<class T>
elemOfBinaryTreeSearch<T> *elemOfBinaryTreeSearch<T>::getNextRight() const {
    return this->nextRight;
}

template<class T>
void elemOfBinaryTreeSearch<T>::setNextRight(elemOfBinaryTreeSearch *nextRight) {
    this->nextRight = nextRight;
}


#endif //LAB3_ELEMOFBINARYTREESEARCH_H
