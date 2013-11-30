#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int N, min, max;
    int ignore1 = -1, ignore2 = -1;
    cin >> N;
    
    int *array = new int[N];
    
    int *biggest = new int[3];
    int *smallest = new int[3];
    
    for (int i=0; i<N; ++i) {
        cin >> array[i];
    }
    
    biggest[0] = -1001;
    biggest[1] = -1001;
    biggest[2] = -1001;
    smallest[0] = 1001;
    smallest[1] = 1001;
    smallest[2] = 1001;
    
    //find the largest value
    for (int i=0; i<N; ++i) {
        if (biggest[0] < array[i]){
            biggest[0] = array[i];
            ignore1 = i;
        }
    }
    
    //find the 2nd largest
    for (int i=0; i<N; ++i) {
        if (biggest[1] < array[i] && ignore1 != i) {
            biggest[1] = array[i];
            ignore2 = i;
        }
    }
    //find the 3rd largest
    for (int i=0; i<N; i++) {
        if (biggest[2] < array[i] && ignore1 != i && ignore2 != i) {
            biggest[2] = array[i];
        }
    }
    
    ignore1 = -1, ignore2 = -1;
    
    //find the smallest
    for (int i=0; i<N; i++) {
        if (smallest[0] > array[i]){
            smallest[0] = array[i];
            ignore1 = i;
        }
    }
    
    //find the second smallest
    for (int i=0; i<N; i++) {
        if (smallest[1] > array[i] && ignore1 != i) {
            smallest[1] = array[i];
            ignore2 = i;
        }
    }
    
    //find the third smallest
    for (int i=0; i<N; i++) {
        if (smallest[2] > array[i] && ignore1 != i && ignore2 != i) {
            smallest[2] = array[i];
        }
    }
    
    //find the max value
    if (biggest[0]*biggest[1]*biggest[2] >= smallest[0]*smallest[1]*biggest[0])
        max = biggest[0]*biggest[1]*biggest[2];
    else
        max = smallest[0]*smallest[1]*biggest[0];
    
    //find the min value
    if (smallest[0]*smallest[1]*smallest[2] <= biggest[0]*biggest[1]*smallest[0])
        min = smallest[0]*smallest[1]*smallest[2];
    else
        min = biggest[0]*biggest[1]*smallest[0];
    
    
    cout << min << " " << max << endl;
}