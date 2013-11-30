#ifndef stackele_h
#define stackele_h

#include <iostream>

class StackEle{
private:
    int pos;
    int num;
    StackEle *left;
    StackEle *right;
public:
	StackEle(int pos, int num); //constructor
    StackEle();
    
    StackEle *getLeft() {return left;} 
    StackEle *getRight() {return right;}
    
    void insertLeft(StackEle *Node) {left = Node;}
    void insertRight(StackEle *Node) {right = Node;}
    
    int getNum() {return num;} //return num
    int getPos() {return pos;} //return postion
};

StackEle::StackEle(int pos, int num) {
    this->pos=pos; this->num=num;
    left = NULL; right = NULL;
}

StackEle::StackEle() {
    pos=0; num=0;
    left=NULL; right=NULL;
}

#endif