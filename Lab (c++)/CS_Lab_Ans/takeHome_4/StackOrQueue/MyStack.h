#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>
#include "MyQueue.h"

using namespace std;

class MyStack {
private:
    vector<int> myStack;
public:
		// Stack operations: push, pop, reverse
    MyStack() {} //constructor
    
    int getTop();
    bool push(const int item);
    bool pop();
    bool reverse();

    bool isEmpty() {return myStack.empty();}
    int getSize() const {return myStack.size();}
};

#endif
