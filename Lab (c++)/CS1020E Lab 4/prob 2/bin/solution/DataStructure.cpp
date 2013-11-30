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
        if (isEmpty()) {push(array[i]);}
        else {
            while (!isEmpty() && getTop()<array[i]) {jump++; pop();}
            
            if (!isEmpty() && getTop()==array[i]) {jump++;}
            if (!isEmpty() && getTop()>array[i]) {jump++; push(array[i]);}
            if (isEmpty()) {push(array[i]);}
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