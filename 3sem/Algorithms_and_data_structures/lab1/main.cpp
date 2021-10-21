#include "headers/listOfInts.h"

int main() {
    listOfInts list;
    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    list.clear();


    return 0;
}