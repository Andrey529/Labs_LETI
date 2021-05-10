#ifndef KURS_ELEMLISTOFCOUNTSTAMPS_H
#define KURS_ELEMLISTOFCOUNTSTAMPS_H

class elemListCountOfStamps{
private:
    int countStamps;
    int denominationOfStamps;
    elemListCountOfStamps *nextElem;
public:
    elemListCountOfStamps();
    void setCountStamps(int i);
    int getCountStamps() const;
    void setDenomination(int i);
    int getDenomination() const;
    void setNextElement(elemListCountOfStamps *elem);
    elemListCountOfStamps *getNextElement();

    bool reduceCountStamps(int i);

};

#endif //KURS_ELEMLISTOFCOUNTSTAMPS_H