/*
 
 */
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> mymap;
    map<string, int>::iterator itr;
    int N, K, Q;
    string sequence, substring;
    
    cin >> N >> K;
    cin >> sequence;
    cin >> Q;
    
    int l = sequence.length();
    for (int i=0; i<l; ++i) {
        if (i+K-1 != l) {
            substring = sequence.substr(i, K);
            itr = mymap.find(substring);
            if (itr != mymap.end())
                mymap.find(substring)->second++;
            else
                mymap.insert(pair<string, int>(substring, 1));
        }
        else
            break;
    }
    
    while (Q>0) {
        cin >> substring;
        itr = mymap.find(substring);
        if (itr == mymap.end())
            cout << 0 << endl;
        else
            cout << mymap.find(substring)->second << endl;
        Q--;
    }

}