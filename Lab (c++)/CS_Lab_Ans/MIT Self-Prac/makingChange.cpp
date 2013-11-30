#include <iostream>
#include <algorithm>

using namespace std;

bool comp (int a, int b ) {
    return b<a;
}

int coinExchange(int *coinTypes, int C, int index, int size, int numOfCoins) {
    if (C==0) 
        return numOfCoins;
    else if (size == index)
        return -1;
    else {
        int A = 0, B = 0;
        if (C >= *coinTypes)
            A = coinExchange(coinTypes, C-*coinTypes, index, size, numOfCoins+1);
        else {
            B = coinExchange(coinTypes+1, C, index+1, size, numOfCoins);
        }
        if (A>0 && B>0)
            return min(A,B);
        else if (A<=0 && B<=0)
            return -1;
        else if (A<=0 && B>0)
            return B;
        else
            return A;
    }
}

int main () {
    int coinTypes[4] = {1, 2, 5, 10};
    int C = 100;
    sort(coinTypes, coinTypes+4, comp);
    
    cout << coinExchange(&coinTypes[0], C, 0, 4, 0) << endl;
}