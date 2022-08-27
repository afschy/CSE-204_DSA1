#ifndef QUEUE_H
#define QUEUE_H

template <typename E> 
class Queue {
private:
    void operator =(const Queue&) {}
    Queue(const Queue&) {}
public:
Queue() {} // Default
    virtual ~Queue() {}
    virtual void clear() = 0;
    virtual void enqueue(const E&) = 0;
    virtual E dequeue() = 0;
    virtual int length() = 0;
    virtual E frontValue() = 0;
    virtual E rearValue() = 0;
    virtual E leaveQueue() = 0;
};

#endif