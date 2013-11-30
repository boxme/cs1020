#ifndef DS_H
#define DS_H

#include <vector>

// your code here
class Tree {
private:
    vector<int> treeHeight;
    int jump;
public:
    Tree(); //constructor
    ~Tree() {if (!isEmpty) {pop();}}
    
    int solve(int array[], int size);
    void push(int item);
    void pop();
    
    bool isEmpty() {return treeHeight.empty();} //return true if the vector is empty
    int getTop() {return treeHeight.back();} //get the last element
};

#endif
