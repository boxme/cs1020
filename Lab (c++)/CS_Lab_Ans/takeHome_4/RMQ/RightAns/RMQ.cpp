#include "RMQ.h"

#include <iostream>
#include <stack>

using namespace std;

void RMQ::setUp() {
    stk.push(StackEle(0, A[0]));
    
    for (int i=1; i<100001; ++i) {
        while (stk.top().num > A[i])
            stk.pop();
        B[i] = stk.top().pos;
        stk.push(StackEle(i, A[i]));
    }
}

int RMQ::getIntervalMin(int c, int d) {
    while (B[d] >= c) {                //stop the loop when the value in B[d] is out of range
        d = B[d];}                    //start searching from d, then moves to the one it's pointing
                                     //B[] holds the position of the element smaller than its A[index]
    return A[d];                    //when B[d] gets out of range, d will give the index of the smallest num of the range
}

int main () {
    int N, Q, i=1, input, c, d;
    
    cin >> N;
    RMQ list(N);             //initializing the arrays
    
    while (N>0) {           
        cin >> input;
        list.addElement(input, i);
        i++;N--;
    }
    
    list.setUp();           //to set up array B[]
    cin >> Q;               //number of queries
    
    while (Q>0) {
        cin >> c >> d;
        cout << list.getIntervalMin(c, d) << endl;
        Q--;
    }
}