#ifndef LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H
#define LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H

#include "iterator.h"
#include "../binaryTreeSearch/elemOfBinaryTreeSearch.h"
#include "../stack/stack.h"

template<class T>
class binaryTreeSearchDepthFirstTraverseIterator : public iterator<T>{   // методов обхода в глубину
private:
    elemOfBinaryTreeSearch<T> *current;
public:
    binaryTreeSearchDepthFirstTraverseIterator(elemOfBinaryTreeSearch<T> *start = nullptr) : current(start) {}
    ~binaryTreeSearchDepthFirstTraverseIterator() = default;
    elemOfBinaryTreeSearch<T> *getCurrent() const;
    void setCurrent(elemOfBinaryTreeSearch<T> *current);


    T next() override;   // продумать, что именно считается следующим элементом,
                        // может понадобится хранить nextRight и nextLeft

    bool hasNext() override;   // нужно дописать нормально

};

#include "../../src/iterators/binaryTreeSearchDepthFirstTraverseIterator.cpp"

#endif //LAB3_BINARYTREESEARCHDEPTHFIRSTTRAVERSEITERATOR_H
