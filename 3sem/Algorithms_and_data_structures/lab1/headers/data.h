#ifndef LAB1_DATA_H
#define LAB1_DATA_H

class data {
private:
    int number;
    data *nextElem;
public:
    data(int number = 0, data *nextElem = nullptr) : number(number), nextElem(nextElem)
    { }
    ~data();

    int getNumber() const;
    void setNumber(int number);
    data *getNextElem() const;
    void setNextElem(data *elem);
};


#endif //LAB1_DATA_H
