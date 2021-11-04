#include <iostream>
#include "src/functions.h"

int main() {

//    int sizeArray = 1000;
//    auto *array = new int[sizeArray];
//    for(int i = sizeArray; i > 0; i--){
//        array[i] = i;
//    }
//    InsertionSort(array,sizeArray);
//    for(int i = 0; i < sizeArray; i++){
//        std::cout << array[i] << ' ';
//    }
//

    std::string str;
    str[0] = '1';
    str[1] = '2';
    str[2] = '3';
    str[3] = '\0';
    std::cout << str;
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
