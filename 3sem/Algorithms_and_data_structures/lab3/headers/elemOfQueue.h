#ifndef LAB3_ELEMOFQUEUE_H
#define LAB3_ELEMOFQUEUE_H

template<class T>
class elemOfQueue{
private:
    T data;
    elemOfQueue *nextElem;
public:
    elemOfQueue();
    elemOfQueue(T data);
    ~elemOfQueue() = default;

    T getData() const;
    void setData(const T data);

    elemOfQueue *getNextElem() const;
    void setNextElem(const elemOfQueue *nextElem);

};

#endif //LAB3_ELEMOFQUEUE_H
