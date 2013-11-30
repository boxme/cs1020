#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "MyStack.h"

using namespace std;

const int max_Size = 20;

class MyQueue {
private:
    int _item[max_Size];
    int _front, _back, _count;
public:
		// Queue operations: enqueue, dequeue, reverse
    MyQueue();
    
    bool enqueue(const int item);
    bool dequeue();
    bool reverse();
    int getFront();
    
    
    bool isEmpty() {return _count==0;}
    int size() {return _count;}
};

#endif
