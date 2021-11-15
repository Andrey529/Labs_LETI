#include <iostream>
#include "headers/queue/queue.h"
#include "headers/stack/stack.h"
#include "headers/binaryTreeSearch/binaryTreeSearch.h"
int main() {

    binaryTreeSearch<double> tree;
    // 4 9 8 10 9 3 5
    tree.insert(4.1);
    tree.insert(9.45);
    tree.insert(8.654);
    tree.insert(10.29);
    tree.insert(9.65);
    tree.insert(3.78);
    tree.insert(5.184);

    std::cout << tree.contains(4.1) << std::endl;


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
