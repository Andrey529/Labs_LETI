#ifndef LAB1_LISTOFINTS_H
#define LAB1_LISTOFINTS_H

#include "data.h"
#include <cstddef>
#include "situations.h"
#include "iostream"

class listOfInts {
private:
    data *head;
public:
    listOfInts(data *elem = nullptr);
    ~listOfInts();

    data *getHead() const;
    void setHead(data *elem);

    bool isEmpty(); // checking if the list is empty

    void push_back(int number); //adding new element in the end of the list
    void push_front(int number); //adding new element in the begin of the list
    void pop_back(); // deleting last element in the list
    void pop_front(); // deleting first element in the list
    void insert(int number, size_t index); // adding an element at index
                            // (insertion before an item that was previously accessible at that index)

    int at(size_t index); // getting an element at the index
                        // тут какаято мутка с возвращаемым значением, спросил про это у препода

    void remove(size_t index); // deleting an element by index
    size_t get_size() const; // getting list size
    void clear(); // removing all list elements
    void set(size_t index, int number); // замена элемента по индексу на передаваемый элемент
                            // replacing the element by index with the passed element


    friend std::ostream& operator<< (std::ostream &out, const listOfInts &list); // Перегрузка оператора вывода <<

    void reverse(); // reverses the order of the elements in the list
};


#endif //LAB1_LISTOFINTS_H
