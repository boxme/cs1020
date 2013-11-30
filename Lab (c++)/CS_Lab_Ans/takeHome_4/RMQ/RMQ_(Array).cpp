//
//  RMQ.cpp
//  helloworld
//
//  Created by Desmond  on 16/3/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include <iostream>

using namespace std;

int main ()
{
    int N, Q, size, i=1;
    int c,d;
    cin >> N; size=N+1;
    
    int sequence[size], temp[size][size];
    
    while (N>0) {cin >> sequence[i++]; N--;}
    
    for (i=1; i<size; ++i) {
        temp[i][i]=i;
        for (int k=i+1; k<size; ++k) {
            if (sequence[temp[i][k-1]] < sequence[k]) {
                temp[i][k]=temp[i][k-1];
            } else
                temp[i][k]=k;
        }
    }
    cin >> Q;
    while (Q>0) {
        cin >> c >> d;
        cout << sequence[temp[c][d]] << endl;
        Q--;
    }
}
