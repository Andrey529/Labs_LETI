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

}

TEST(pop_back,listNotEmpty){

}

TEST(pop_front, listEmpty){

}

TEST(pop_front,listNotEmpty){

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}