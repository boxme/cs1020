#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    int N = 0, pos = 0, numTri = 0 , numRight = 0;
    cin >> N;
    int *arr = new int[N];
    
    while (N>0) {
        cin >> arr[pos];
        pos++;
        N--;
    }
    sort(arr, arr+pos); //sort method for array
//    cout << sizeof(arr)/sizeof(int) << endl; // to index of the last slot of array
    
    for (int i=0; i<pos-2; ++i) {
        for (int j=i+1; j<pos-1; ++j) {
            int k = j+1;
            while (k<pos && arr[k] < arr[i]+arr[j]) {
                if (pow(arr[k], 2) == (pow(arr[i], 2) + pow(arr[j], 2))) {
                    numRight++;
                }
                k++;
                numTri++;
            }
        }
    }
    cout << numTri << " " << numRight << endl;
}