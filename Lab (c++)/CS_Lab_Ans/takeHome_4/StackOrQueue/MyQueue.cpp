#include "MyQueue.h"

// your implementation goes here

MyQueue::MyQueue() {
    _front=0; _back= max_Size-1; _count=0;
}

int MyQueue::getFront() {
    return _item[_front];
}

bool MyQueue::enqueue(const int item) {
    _back = (_back+1)%max_Size;  //wrap around array
    _item[_back] = item; ++_count; //enqueue only affects the back
    return true;
}

bool MyQueue::dequeue() {
    if (isEmpty()) {return false;}
    else {_front = (_front+1)%max_Size; --_count; return true;}
}

bool MyQueue::reverse() {
    MyStack tmps;
    while (!this->isEmpty()) {tmps.push(this->getFront()); this->dequeue();}
    while (!tmps.isEmpty()) {this->enqueue(tmps.getTop()); tmps.pop();}
    return true;
}
