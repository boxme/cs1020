//
//  main.cpp
//  helloworld
//
//  Created by Desmond  on 17/1/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool lowercase (char a, char b)
{
    return tolower(a)<tolower(b);
}

int main ()
{
    char string1[100] = {};
    char string2[100] = {};
    
    cin >> string1;
    cin >> string2;
    
    if (lexicographical_compare(string1, string1+100, string2, string2+100, lowercase)) {
        cout << "1" << endl;
    } else if (lexicographical_compare(string2, string2+100, string1, string1+100, lowercase)) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }
    
}