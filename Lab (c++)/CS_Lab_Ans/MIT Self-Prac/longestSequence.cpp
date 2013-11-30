#include <iostream>
#include <algorithm>

using namespace std;

int longestSeq(int *array, int length, int size, int index) {
    if (index == size || *array == *(array-1))
        return length;
    else 
        return longestSeq(array+1, length+1, size, index+1);
}

int main ()
{
    int array[5] = {10, 4, 42, 42, 9};
    sort(array, array+5);
    
    cout << longestSeq(&array[1], 1, 5, 1) << endl;
}