#include <iostream>
#include <string>

using namespace std;

void NChooseK(string letters, int K, string output) {
    if (K==0) {
        cout << output << endl;
    }
    else if (letters.length() == K) {
        output += letters;
        cout << output << endl;
    }
    else {
        NChooseK(letters.substr(1), K-1, output+letters.substr(0,1));
        NChooseK(letters.substr(1), K, output);
    }
}

int main()
{
    int K=0;
    string letters, result;
    
    cin >> K >> letters;
    NChooseK(letters, K, result);
}