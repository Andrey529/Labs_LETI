#include "headers/listOfInts.h"

int main() {
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    int a = list.at(10);
    std::cout << a << std::endl;
    return 0;
}
