#include "gtest/gtest.h"
#include "../src/functions.h"

class TestSortingFunctionsOfArrayInts : public ::testing::Test {
protected:
    int *randomArrayOfInts;
    int *notRandomArrayOfInts;
    int dataSize;
    int arraySize;
    std::string string;
public:
    TestSortingFunctionsOfArrayInts() {
        this->randomArrayOfInts = nullptr;
        this->notRandomArrayOfInts = nullptr;
        this->arraySize = 0;
        this->dataSize = 0;
    }
    ~TestSortingFunctionsOfArrayInts() {
        delete[] this->randomArrayOfInts;
        delete[] this->notRandomArrayOfInts;
    }
    int *SetUpRandomArrayOfInts() {
        auto *array = new int[this->arraySize];
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
        std::uniform_int_distribution<> range(-this->dataSize, this->dataSize);
        for (int i = 0; i < this->arraySize; i++){
            array[i] = char (range(generator));
        }
        return array;
    }
    int *SetUpNotRandomArrayOfInts() {
        auto *array = new int[this->arraySize];
        for(int i = this->dataSize-1; i >= 0; i--){
            array[i] = i;
        }
        return array;
    }
    std::string SetUpArrayOfChars() {
        std::string str;
        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
        std::uniform_int_distribution<> range(0, 255);
        for(int i = 0; i < this->arraySize; i++){
            str[i] = range(generator);
        }
        str[arraySize] = '\0';
        return str;
    }
};

TEST_F(TestSortingFunctionsOfArrayInts, InsertionSort){
    this->arraySize = 1000;
    this->dataSize = 1000;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    InsertionSort(this->randomArrayOfInts,this->arraySize);
    for (int i = 1; i < this->arraySize; i++)  ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, QuickSort){
    this->arraySize = 1000;
    this->dataSize = 1000;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    QuickSort(this->randomArrayOfInts,0,this->arraySize-1);
    for (int i = 1; i < this->arraySize; i++)  ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, BogoSort){
    this->arraySize = 10;
    this->dataSize = 5;
    this->randomArrayOfInts = SetUpRandomArrayOfInts();
    BogoSort(this->randomArrayOfInts,this->arraySize);
    for (int i = 1; i < this->arraySize; i++)  ASSERT_GE(this->randomArrayOfInts[i],this->randomArrayOfInts[i-1]);
}

TEST_F(TestSortingFunctionsOfArrayInts, BinarySearch){
    this->dataSize = 100;
    this->arraySize = 100;
    this->notRandomArrayOfInts = SetUpNotRandomArrayOfInts();
    int index = BinarySearch(this->notRandomArrayOfInts, this->arraySize,50);
    ASSERT_EQ(notRandomArrayOfInts[index],notRandomArrayOfInts[50]);
}

TEST_F(TestSortingFunctionsOfArrayInts, CountingSort){
    this->arraySize = 100;
    this->string = SetUpArrayOfChars();
    CountingSort(this->string);
    for (int i = 1; i < this->arraySize; i++)  ASSERT_GE(this->string[i],this->string[i-1]);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}