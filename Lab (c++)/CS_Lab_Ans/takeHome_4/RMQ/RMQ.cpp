#include "RMQ.h"
#include <iostream>

using namespace std;

void RMQ::addElement(const int &x) {
    A.push_back(x);
}

void RMQ::clear() {
    while (!stk.empty()) {stk.pop();}
}

void RMQ::insertRootNode() {
    int pos=1, num = A.front();
    StackEle *Node = new StackEle(pos, num); //create the first node
    root = Node;     //first node is always the root
    stk.push(Node); //push the node into the stack
    A.erase(A.begin()); //delete the first element
    
    buildTree(); //build the rest of the tree
}

void RMQ::buildTree() {
    int pos=2;
    
    while (A.size()>0) {  //when vector is empty, the tree is completed with all the elements
        StackEle *newNode = new StackEle(pos, A.front()); //pos must increase by 1
        
        while (stk.size() > 0 && stk.top()->getNum() > newNode->getNum()) { //stop if stack is empty of node is smaller or equal to newNode
            StackEle *cur = stk.top();
            cur->insertRight(newNode->getLeft()); //cur will insert right of whatever is on the left of newNode; 
            newNode->insertLeft(cur);
            stk.pop(); //remove the bigger value node from the stack.
        }
        
        if (stk.size() == 0) {root = newNode;} //if stack is empty. newNode is the new root of the tree
        else {stk.top()->insertRight(newNode);}  //newNode becomes the right side of the top element.
        
        stk.push(newNode); //push the newNode into the stack after all the operation
        A.erase(A.begin()); //erase the front element from the vector
        pos++;
    }
}

int RMQ::getIntervalMin(int c, int d, StackEle *cur) {
    if (cur->getPos() >= c && cur->getPos() <= d) { //base case
        return cur->getNum();
    } else {
        if (cur->getPos() < c) {cur = cur->getRight();}      //if pos is smaller than c, traverse left. else traverse right
        else if (cur->getPos() > d) {cur = cur->getLeft();}
    }
   return getIntervalMin(c, d, cur);       //recursive call
}

//int RMQ::getIntervalMin(int c, int d) {
//    StackEle *cur = root;
//    while (true) {
//        if (cur->getPos() >= c && cur->getPos() <= d) {
//            return cur->getNum();
//        } else {
//            if (cur->getPos() < c) {cur = cur->getLeft();}
//            else {cur = cur->getRight();}
//        }
//    }
//}

int main ()
{
    int N, Q, c, d, input;
    RMQ list;
    StackEle *cur;
    
    cin >> N; //num of integer    
    while (N>0) {
        cin >> input; list.addElement(input); //add elements into vector
        N--;
    }
    
    list.insertRootNode(); //building the tree
    
    cin >> Q; //num of queries
    while (Q>0) {
        cin >> c >> d;     //get the range c to d
        cur = list.getRoot();
        cout << list.getIntervalMin(c, d, cur) << endl;
    }
}
