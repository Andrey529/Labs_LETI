#ifndef KURS_RATEVALUES_H
#define KURS_RATEVALUES_H

class rateValues{
private:
    int lowerBound;
    int upperBound;
    int oldPrice;
    int newPrice;

    rateValues *next;
public:
    rateValues();
    void setLowerBound(int i);
    int getLowerBound() const;
    void setUpperBound(int i);
    int getUpperBound() const;
    void setOldPrice(int i);
    int getOldPrice() const;
    void setNewPrice(int i);
    int getNewPrice() const;

    void setNext(rateValues *elem);
    rateValues *getNext();
};

#endif //KURS_RATEVALUES_H
