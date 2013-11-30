#include "DataStructure.h"
#include <sstream>
#include <iostream>

BallList::BallList() {
    _size = 0;
    _head = NULL;
}

BallList::~BallList() {
    while (!isEmpty()){
        erase(1);
    }
}

string BallList::print() {
    Ball *cur = new Ball;
    ostringstream oss;
    string output;
    
    for (int i=1; i<=getLength(); ++i) {
//        cout << getLength() << endl;
        cur = traverse(i);
//        cout << cur->value << endl;
        oss << cur->value << " ";
    }
    return output = oss.str();
}

BallList::Ball *BallList::traverse(int index) {
    Ball *cur = new Ball;
    if (index < 1 || index > getLength()) {
        return NULL;
    } else {
        cur = _head;
        for (int i=1; i<index; ++i) {
            cur = cur->p_next;
        }
    }
    return cur;
}

int BallList::search(int num) {
    int index = 0;
    Ball *cur = new Ball;
    cur = _head;
    
    if (cur->value == num) {
        index = 1;
        return index;
    } else {
        for (int i=2; i<=getLength(); ++i) {
            cur = cur->p_next;
            if (cur->value == num) {
                index = i;
                return index;
            }
        }
    }
    return index;
}

void BallList::insert(int num) {
    Ball *newBall = new Ball;
    newBall->value = num;
    newBall->p_next = NULL;
    newBall->p_prev = NULL;
    
    int newLength = getLength() + 1;
    
    if (newLength == 1) {
        _head = newBall;
    } else {
        Ball *cur = traverse(getLength());
        cur->p_next = newBall;
        newBall->p_prev = cur;
    }
    _size = newLength;
}

void BallList::erase(int num) {
    Ball *cur = new Ball;
    Ball *prev = new Ball;
    cur = traverse(search(num));
    
    if (cur == _head) {
        _head = cur->p_next;
    } else if (cur != NULL) {
        if (search(num) != getLength()) {
            prev = cur->p_prev;
            prev->p_next = cur->p_next;
            cur->p_next->p_prev = prev;
        }
    }
    delete cur;
    _size--;
}

void BallList::check(string action, int x, int y) {
    if (action == "A") {
        if (search(x) != search(y)-1) {
            erase(x);
            change(action, x, search(y));
        }
    } else if (action == "B"){
        if (search(x) != search(y)+1) {
            erase(x);
            change(action, x, search(y));
        }
    }
}

void BallList::change(string action, int x, int index) {
    Ball *newBall = new Ball;
    newBall->value = x;
    
    if (action == "A"){
        if (index == 1) {
            newBall->p_next = _head;
            _head->p_prev = newBall;
            _head = newBall;
        } else {
            Ball *cur = traverse(index);
            newBall->p_next = cur;
            newBall->p_prev = cur->p_prev;
            cur->p_prev = newBall;
            newBall->p_prev->p_next = newBall;
        }
    } else {
        if (index == 1) {
            newBall->p_prev = _head;
            newBall->p_next = _head->p_next;
            _head->p_next = newBall;
            newBall->p_next->p_prev = newBall;
        } else {
            Ball *cur = traverse(index);
            
            if (index == getLength()) {
                newBall->p_prev = cur;
                cur->p_next = newBall;
            } else {
                newBall->p_next = cur->p_next;
                newBall->p_prev = cur;
                cur->p_next = newBall;
                newBall->p_next->p_prev = newBall;
            }
        }
    }
    _size++;
}
