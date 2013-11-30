#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Box {
    int h, w, d;
};

//int compareMyType (const void * a, const void * b)
//{
//    if ( *(MyType*)a <  *(MyType*)b ) return -1;  <0, a goes before b
//    if ( *(MyType*)a == *(MyType*)b ) return 0;   equvalent
//    if ( *(MyType*)a >  *(MyType*)b ) return 1;   >0 a goes after b
//}

int cmp(const void *a, const void *b) {
    return ((*(Box *)b).w * (*(Box *)b).d) - ((*(Box*)a).w * (*(Box*)a).d);
}

//rotate the box 
void rotate(Box arr[], int N, Box rot[]) {
    int index = 0;
    for (int i=0; i<N; ++i) {
        
        //copy the original box
        rot[index].h = arr[i].h;
        rot[index].w = arr[i].w;
        rot[index].d = arr[i].d;
        index++;
        
        //rotate once
        rot[index].h = arr[i].w;
        rot[index].w = arr[i].d;
        rot[index].d = arr[i].h;
        index++;
        
        //rotate second time
        rot[index].h = arr[i].d;
        rot[index].w = arr[i].h;
        rot[index].d = arr[i].w;
        index++;
    }
}

//printing the array
void print(Box rot[], int N) {
    for (int i=0; i<3*N; ++i) {
        cout << rot[i].h << " " << rot[i].w << " " << rot[i].d << endl;
    }
}

//recursive to find the height obtained with different base area
int tallest(Box rot[], int N, int index, int compIndex, int height) {
    if (index == N)
        return height;
    else {
        if (rot[compIndex].w > rot[index].w && rot[compIndex].d > rot[index].d)
            return tallest(rot, N, index+1, index, height+rot[index].h);
        else
            return tallest(rot, N, index+1, compIndex, height);
    }
}

int main ()
{
    Box arr[4] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int N = sizeof(arr)/sizeof(arr[0]);
    Box rot[3*N];
    int length[3*N];
    
    // rotating the box
    rotate(arr, N, rot);
    
    //sort in decreasing base area
    qsort(rot, 3*N, sizeof(rot[0]), cmp);
    
    for (int i=0; i<3*N; ++i) {
        length[i] = rot[i].h;
        length[i] += tallest(rot, 3*N, i+1, i, 0);
    }
        
    //finding the max height
    int maxHeight = -1;
    for (int i=0; i<3*N; ++i) {
        if (maxHeight < length[i])
            maxHeight = length[i];
    }
    cout << maxHeight << endl;
}