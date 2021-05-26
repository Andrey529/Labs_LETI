#ifndef KURS_ELEMENTOFSTIKEREDSTAMPS_H
#define KURS_ELEMENTOFSTIKEREDSTAMPS_H

class elementOfStikeredStamps{
private:
    int denomination = -1;
    int needUnits = -1;
    int countStamps = -1;
    elementOfStikeredStamps *nextStamp = nullptr;
public:
    void setDenomination(int i){
        this->denomination = i;
    }
    int getDenomination() const{
        return this->denomination;
    }
    void setNeedUnits(int i){
        this->needUnits = i;
    }
    int getNeedUnits() const{
        return this->needUnits;
    }
    void setCountStamps(int i){
        this->countStamps = i;
    }
    int getCountStamps() const{
        return this->countStamps;
    }
    void setNextStamp(elementOfStikeredStamps *elem){
        this->nextStamp = elem;
    }
    elementOfStikeredStamps *getNextStamp() const{
        return this->nextStamp;
    }
};

#endif //KURS_ELEMENTOFSTIKEREDSTAMPS_H