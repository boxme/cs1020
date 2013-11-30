#include "DataStructure.h"
#include <iostream>

using namespace std;

Tree::Tree() {
    jump=0;
}

void Tree::push(int item) {
    treeHeight.push_back(item);
}

void Tree::pop() {
    treeHeight.pop_back();
}

int Tree::solve(int array[], int size) {
    for (int i=1; i<=size; ++i) {
        if (isEmpty()) {push(array[i]);} //when the stack is empty, push in and do not increase the count
        else {
            while (!isEmpty() && getTop()<array[i]) {jump++; pop();}  //if the tree is not empty, compare the height with the top
            
            if (!isEmpty() && getTop()==array[i]) {jump++;} //if the top and the cur tree has the same height, increase jump
            if (!isEmpty() && getTop()>array[i]) {jump++; push(array[i]);} //if top is taller, pop it and increase by 1 for every pop
            if (isEmpty()) {push(array[i]);} //if list is empty, push and do not increase count
        }
    }
    return jump;
}


int main()
{
    int N;
    cin >> N;
    
    int array[N]; Tree numOfJump;
    
    for (int i=1; i<=N; ++i) {
        cin >> array[i];
    }
    
   cout << numOfJump.solve(array, N) << endl;
}