#include <iostream>
#include <algorithm>

using namespace std;

int chooseSticks(int *lengthOfSticks, int length, int minSticks, int numOfSticks) {
    if (length==0) {return minSticks;}
    else if (length < *lengthOfSticks || numOfSticks==0) {return minSticks = -1;}
    else {
       int a = chooseSticks(lengthOfSticks+1, length-(*lengthOfSticks), minSticks+1, numOfSticks-1);
       int b = chooseSticks(lengthOfSticks+1, length, minSticks, numOfSticks-1);
        if (a>0 && b<0)
            return a;
        else if (a<0 && b>0)
            return b;
        else
            return min(a,b);
    }
}

int main ()
{
    int numOfSticks, desiredLength;
    cin >> numOfSticks >> desiredLength;
    
    int *lengthOfSticks = new int[numOfSticks];    
    for (int i=0; i<numOfSticks; i++) {cin >> lengthOfSticks[i];}
    
    sort(lengthOfSticks, lengthOfSticks+numOfSticks);
    
    cout << chooseSticks(&lengthOfSticks[0], desiredLength, 0, numOfSticks) << endl;
}