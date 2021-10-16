#include "gtest/gtest.h"
#include "../headers/listOfInts.h"

TEST(getHead,headNULL){
    listOfInts list;
    ASSERT_EQ(list.getHead(), nullptr);
}

TEST(getHead,headNotNULL){
    listOfInts list;
    for (int i = 0; i < 3; i++){
        list.push_back(i);
    }
    ASSERT_NE(list.getHead(), nullptr);
}

TEST(setHead,headNULL){
    listOfInts list;
    list.push_back(0);
    data *elem = list.getHead();
    list.setHead(nullptr);
    delete elem;
    ASSERT_EQ(list.getHead(), nullptr);
}

TEST(setHead,headNotNULL) {
    listOfInts list;
    for(int i = 0; i < 3; i++){
        list.push_back(i);
    }

    auto *newHead = new data(10);

    newHead->setNextElem(list.getHead());

    list.setHead(newHead);

    ASSERT_EQ(list.getHead(),newHead);
}

TEST(isEmpty, listIsEmpty){
    listOfInts list;
    ASSERT_EQ(list.getHead(), nullptr);
}

TEST(isEmpty, listNotEmpty){
    listOfInts list;
    for(int i = 0; i < 3; i++){
        list.push_back(i);
    }
    ASSERT_NE(list.getHead(), nullptr);
}

TEST(push_back,listEmpty){
    listOfInts list;
    list.push_back(5);

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_EQ(list.getHead()->getNumber(),5);
}

TEST(push_back,listNotEmpty){
    listOfInts list;

    auto *elem0 = new data(0);
    auto *elem1 = new data(1);
    auto *elem2 = new data(2);

    list.setHead(elem0);
    elem0->setNextElem(elem1);
    elem1->setNextElem(elem2);
    elem2->setNextElem(nullptr);

    list.push_back(5);

    data *lastElem = list.getHead();
    while (lastElem->getNextElem() != nullptr){
        lastElem = lastElem->getNextElem();
    }

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_EQ(lastElem->getNumber(),5);
}

TEST(push_front,listEmpty){
    listOfInts list;
    list.push_front(5);

    ASSERT_NE(list.getHead(), nullptr);
    ASSERT_EQ(list.getHead()->getNumber(),5);
}

TEST(push_front,listNotEmpty){
    listOfInts list;
    for(int i = 0; i < 3; i++){
        list.push_back(i);
    }

    data *previousHead = list.getHead();
    list.push_front(5);

    ASSERT_EQ(list.getHead()->getNumber(),5);
    ASSERT_EQ(list.getHead()->getNextElem(),previousHead);
}

TEST(pop_back, listEmpty){
    listOfInts list;
    list.pop_back();
    ASSERT_EQ(list.getHead(),nullptr);
}

TEST(pop_back,listNotEmpty){
    listOfInts list;
    for( int i = 0; i < 3; i++){
        list.push_back(i);
    }

    list.pop_back();

    data *elem = list.getHead();
    while(elem->getNextElem() != nullptr){
        elem = elem->getNextElem();
    }

    ASSERT_EQ(elem->getNumber(),1);
}

TEST(pop_front, listEmpty){
    listOfInts list;
    list.pop_front();
    ASSERT_EQ(list.getHead(),nullptr);
}

TEST(pop_front,listNotEmpty){
    listOfInts list;
    for( int i = 0; i < 3; i++){
        list.push_back(i);
    }

    list.pop_front();

    ASSERT_EQ(list.getHead()->getNumber(),1);
}

TEST(insert,listEmptyIndex0){
    listOfInts list;

    ASSERT_NO_THROW(list.insert(5,0));

    ASSERT_EQ(list.getHead()->getNumber(),5);
}

TEST(insert,listEmptyIndex5){
    listOfInts list;

    ASSERT_NO_THROW(list.insert(5,5));
    ASSERT_EQ(list.getHead()->getNumber(),5);
}

TEST(insert,listNotEmptyIndex0){
    listOfInts list;

    for (int i = 0; i < 3; i++){
        list.push_back(i);
    }

    list.insert(5,0);

    ASSERT_EQ(list.getHead()->getNumber(),5);

    data *nextElement = list.getHead()->getNextElem();
    ASSERT_EQ(nextElement->getNumber(),0);
}

TEST(insert,listNotEmptyIndexLastElement){
    listOfInts list;

    for (int i = 0; i < 3; i++){
        list.push_back(i);
    }

    list.insert(5,2);

    data *insertedElem = list.getHead();

    for(int i = 0; i < 2; i++){
        insertedElem = insertedElem->getNextElem();
    }
    ASSERT_EQ(insertedElem->getNumber(),5);  // inserted element has index = 2

    data *nextAfterInsertedElem = insertedElem->getNextElem();

    ASSERT_EQ(nextAfterInsertedElem->getNextElem(), nullptr); // next element after last element = nullptr
    ASSERT_EQ(insertedElem->getNextElem()->getNumber(),2);  // last element number = 2
}

TEST(insert,listNotEmptyIndexNotLastAndNotBeginElement){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    list.insert(100,2);

    data *previousElem;
    data *nextElem;
    data *insertedElem = list.getHead();

    for(int i = 0; i < 4; i++){
        if(i == 1) previousElem = insertedElem;
        if(i == 2) break;
        insertedElem = insertedElem->getNextElem();

    }

    nextElem = insertedElem->getNextElem();

    ASSERT_EQ(previousElem->getNextElem(),insertedElem);
    ASSERT_EQ(previousElem->getNumber(),1);
    ASSERT_EQ(insertedElem->getNumber(),100);
    ASSERT_EQ(nextElem->getNumber(),2);
}

TEST(insert,listNotEmptyIndexMoreThanSizeList){
    listOfInts list;

    for(int i = 0; i < 5; i++){
        list.push_back(i);
    }

    ASSERT_NO_THROW(list.insert(100,10));
    int i = 0;

    data *elem = list.getHead();
    while(elem != nullptr){
        i++;
        elem = elem->getNextElem();
    }
    ASSERT_EQ(i,5);
}

TEST(at,listEmpty){
    listOfInts list;
    ASSERT_NO_THROW(list.at(0));
}

TEST(at,listNotEmpty){
    listOfInts list;

    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    int number = list.at(2);

//    ASSERT_NO_THROW(list.at(2));   cacaito dich
    ASSERT_EQ(number,2);
}

TEST(set, listEmpty){
    listOfInts list;

    ASSERT_NO_THROW(list.set(3,100));
}

TEST(set, listNotEmptyIndex0){
    listOfInts list;

    for (int i = 0; i < 5; i++){
        list.push_back(i);
    }

    data *nextPreviousHead = list.getHead()->getNextElem();
//    ASSERT_ANY_THROW(list.set(0,100));
//    list.set(0,100);
    ASSERT_EQ(list.getHead()->getNumber(),100);
    ASSERT_EQ(list.getHead()->getNextElem(),nextPreviousHead);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}