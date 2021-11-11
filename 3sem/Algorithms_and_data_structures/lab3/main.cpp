#include <iostream>
#include "headers/queue/queue.h"
#include "headers/stack/stack.h"
int main() {

    {
        queue<int> queue(0);
        for (int i = 1; i <= 5; i++) {
            queue.push(i);
        }

        elemOfQueue<int> *front = queue.getFront();
        elemOfQueue<int> *back = queue.getBack();
        std::cout << "Queue is empty:" << queue.isEmpty() << std::endl;
        std::cout << "Queue size = " << queue.getSize() << std::endl;
        queue.pop();
        queue.pop();
        std::cout << "Queue size = " << queue.getSize() << std::endl;
    }
    {
        stack<int> stack(0);
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }

        elemOfStack<int> *front = stack.getFront();
        elemOfStack<int> *back = stack.getBack();
        std::cout << "Stack is empty:" << stack.isEmpty() << std::endl;
        std::cout << "Stack size = " << stack.getSize() << std::endl;
        stack.pop();
        stack.pop();
        std::cout << "Stack size = " << stack.getSize() << std::endl;

    }

    return 0;
}
