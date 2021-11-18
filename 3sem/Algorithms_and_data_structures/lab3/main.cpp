#include <iostream>
#include "headers/queue/queue.h"
#include "headers/stack/stack.h"
#include "headers/binaryTreeSearch/binaryTreeSearch.h"
#include <string>
int main() {

//    elemOfBinaryTreeSearch<int> elem(5);
//
//    binaryTreeSearch<int> tree;
//    tree.insert(elem.getData());
//    auto *Queue = new queue<elemOfBinaryTreeSearch<int>>(elem);

//    auto *current = new elemOfBinaryTreeSearch(5);
//    auto *Queue = new queue<elemOfBinaryTreeSearch<int>>();

    binaryTreeSearch<int> tree;
    // 4 9 8 10 9 3 5
    tree.insert(4);
    tree.insert(8);
    tree.insert(7);
    tree.insert(10);
    tree.insert(8);
    tree.insert(2);
    tree.insert(6);
    tree.insert(11);
    tree.insert(1);
    tree.insert(3);
    tree.insert(0);
    tree.insert(9);

    iterator<elemOfBinaryTreeSearch<int>> *treeIterator = tree.create_bft_iterator();
    while (treeIterator->hasNext()) {
        std::cout << treeIterator->next().getData() << ' ';
    }


////    std::cout << tree.contains(4.1) << std::endl;
//
//    tree.remove(8);


//    {
//        queue<int> queue(0);
//        for (int i = 1; i <= 5; i++) {
//            queue.push(i);
//        }
//
//        elemOfQueue<int> *front = queue.getFront();
//        elemOfQueue<int> *back = queue.getBack();
//        std::cout << "Queue is empty:" << queue.isEmpty() << std::endl;
//        std::cout << "Queue size = " << queue.getSize() << std::endl;
//        queue.pop();
//        queue.pop();
//        std::cout << "Queue size = " << queue.getSize() << std::endl;
//    }
//    {
//        stack<int> stack(0);
//        for (int i = 1; i <= 5; i++) {
//            stack.push(i);
//        }
//
//        elemOfStack<int> *front = stack.getFront();
//        elemOfStack<int> *back = stack.getBack();
//        std::cout << "Stack is empty:" << stack.isEmpty() << std::endl;
//        std::cout << "Stack size = " << stack.getSize() << std::endl;
//        stack.pop();
//        stack.pop();
//        std::cout << "Stack size = " << stack.getSize() << std::endl;
//
//    }

    return 0;
}
