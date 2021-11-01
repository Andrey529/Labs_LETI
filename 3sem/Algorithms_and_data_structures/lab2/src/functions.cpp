#include "functions.h"

int BinarySearch(const int* array, int arraySize, int searchValue) {
    bool flag = false;
    int high = arraySize - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while ((!flag) and (high >= low)) {
        if (searchValue == array[middle])
            flag = true;
        else{
            if (searchValue < array[middle])
                high = middle - 1;
            else
                low = middle + 1;
        }
        middle = (high + low) / 2;
    }
    return (flag) ? middle : -1;
}

void QuickSort(int* array, int low, int high) {
    int left = low;
    int right = high;
    int middle = array[(left + right) / 2];
    int temp;

    while (left <= right){
        while (array[left] < middle)
            left++;
        while (array[right] > middle)
            right--;
        if (left <= right){
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    if (right > low)
        QuickSort(array, low, right);
    if (left < high)
        QuickSort(array, left, high);
}

void InsertionSort(int* array, int arraySize) {
    int temp, i, j;
    for (i = 1; i < arraySize; i++){
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}



void swapElements(int* elem1, int* elem2) {
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

bool isArraySorted(const int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void BogoSort(int* array, int arraySize) {
    int temp = arraySize;
    while (!isArraySorted(array, arraySize)) {
        std::random_device rd;
        std::mt19937 mersenne(rd());
        while (arraySize > 1) {
            int randomIndex = mersenne();
            arraySize -= 1;
            swapElements(&array[randomIndex], &array[arraySize]);
        }
        arraySize = temp;
    }
}


void comprasionQuickSortAndInsertionSort(){
    int dataSize = 10;
    while (dataSize != 10000) { // datasize = 10 -> 100 -> 1 000 -> 10 000 -> 100 000
        double meanValueForQuickSort = 0;
        double meanValueForInsertionSort = 0;
        for (int runNumber = 0; runNumber < 10; runNumber++) { // 10 differnt runs for one dataSize
            std::random_device rd;
            std::mt19937 mersenne(rd());

            auto *arrayForQuickSort = new int[dataSize];
            auto *arrayForInsertionSort = new int[dataSize];
            for (int i = 0; i < dataSize; i++){ // generate 2 array of random values
                arrayForQuickSort[i] = mersenne() % dataSize;
                arrayForInsertionSort[i] = arrayForQuickSort[i];
//                std::cout << arrayForQuickSort[i] << ' ';
            }
//            std::cout << std::endl;

//            for (int i = 0; i < dataSize; i++){
//                std::cout << arrayForInsertionSort[i] << ' ';
//            }
//            std::cout << std::endl;


            auto start = std::chrono::high_resolution_clock::now();
            QuickSort(arrayForQuickSort,0,dataSize-1);
//            for (int i = 0; i < dataSize; i++) {
//                std::cout << arrayForQuickSort[i] << ' ';
//            }
//            std::cout << std::endl;
            auto finish = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
            meanValueForQuickSort += finish.count();
//            std::cout << "QuickSort: " << finish.count() << "ns." << std::endl;


            start = std::chrono::high_resolution_clock::now();
            InsertionSort(arrayForInsertionSort,dataSize);
//            for (int i = 0; i < dataSize; i++) {
//                std::cout << arrayForQuickSort[i] << ' ';
//            }
//            std::cout << std::endl;
            finish = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
            meanValueForInsertionSort += finish.count();
//            std::cout << "InsertionSort: " << finish.count() << "ns." << std::endl;


            delete[] arrayForQuickSort;
            delete[] arrayForInsertionSort;
        }


        std::cout << "dataSize = " << dataSize << std::endl;
        std::cout << "\tmeanValueForQuickSort = " << meanValueForQuickSort/10 << std::endl;
        std::cout << "\tmeanValueForInsertionSort = " << meanValueForInsertionSort/10 << std::endl;
        dataSize *= 10;
    }
}