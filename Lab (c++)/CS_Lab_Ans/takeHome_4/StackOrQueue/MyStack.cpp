#include "MyStack.h"

int MyStack::getTop() {
    int stackTop;
    return stackTop = myStack.back();
}

bool MyStack::push(const int item) {
    myStack.push_back(item);
    return true;
}

bool MyStack::pop() {
    if (isEmpty()) {return false;}
    else {myStack.pop_back(); return true;}
}

bool MyStack::reverse() {
    MyQueue tmpq;
    while (!this->isEmpty()) {tmpq.enqueue(this->getTop()); this->pop();}
    while (!tmpq.isEmpty()) {this->push(tmpq.getFront()); tmpq.dequeue();}
    return true;
}

