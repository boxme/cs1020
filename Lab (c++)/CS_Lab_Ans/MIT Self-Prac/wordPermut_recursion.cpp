#include <iostream>
#include <string>

using namespace std;

void recPermut(string sofar, string rest) {
    if (rest.empty())
        cout << sofar << endl;
    else {
        for (int i=0; i<rest.length(); i++) {
            string remaining = rest.substr(0, i) + rest.substr(i+1); //substr(i+1) will take out 1 letter
            recPermut(sofar+rest[i], remaining);
        }
    }
}

int main ()
{
    string str = "its", sofar = "";
    cout << str.substr(0,1) + str.substr(2) << endl;
    cout << str.length() << endl;
    recPermut(sofar, str);
}