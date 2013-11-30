#include <iostream>
#include "DataStructure.h"
using namespace std;

int main ()
{
    int N, M, x, y;
    string action;
    BallList list;
    
    cin >> N >> M;
    
    for (int i=1; i<=N; ++i) {
        list.insert(i);
    }
    
    while (M>0) {
        cin >> action;
        if (action == "A" || action == "B") {
            cin >> x >> y;
            list.check(action, x, y);
        } else {
            cin >> x;
            list.erase(x);
        }
//        cout << list.print() << endl;
        M--;
    }
        cout << list.print() << endl;
//    list.print();
}
