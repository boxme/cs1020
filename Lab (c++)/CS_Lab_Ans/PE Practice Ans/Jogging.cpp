#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
    int T;
    int totalTime, upHill, flat, downHill, i=0;
    int timeForward=0, timeBack=0, dist=0;
    
    cin >> totalTime >> T >> upHill >> flat >> downHill;
    char *route = new char[T];
    
    for (i=0; i<T; i++)
        cin >> route[i];
    
    i=0;
    
    while (true) {
        switch (route[i]) {
            case 'u':
                timeForward += upHill;
                timeBack += downHill;
                break;
            case 'f':
                timeForward += flat;
                timeBack += flat;
                break;
            case 'd':
                timeForward += downHill;
                timeBack += upHill;
        }
        
        if (totalTime < timeForward + timeBack) {break;}
        i++;
        dist++;
        if (i==T) {break;}
    }
    cout << dist << endl;
}