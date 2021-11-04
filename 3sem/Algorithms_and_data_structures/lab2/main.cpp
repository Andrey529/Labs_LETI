#include <iostream>
#include "src/functions.h"

int main() {

    std::string str = "hgfedcba";
    CountingSort(str);
    std::cout << str << std::endl;

//    comprasionQuickSortAndInsertionSort();
//
//    auto *array = new int[10];
//    BinarySearch(array, 10, 7);
//    QuickSort(array,0, 9);
//    InsertionSort(array, 10);
//    BogoSort(array, 10);
//    delete[] array;

    return 0;
}
