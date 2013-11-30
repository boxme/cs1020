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

int AND (int a, int b)
{
    if (a == 1 && b == 1) {
        return 1;
    } else {
        return 0;
    }
}

int OR (int a, int b)
{
    if (a == 0 && b == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main ()
{
    int A = 0;
    int B = 0;
    string binary = "";
    int array[100] = {0};
    int type = 0;
    int N = 0;
    int y = 0;
    
    cin >> type;
    
    if (type == 1) {
        cin >> N;
        
        for (int x = 0; x < N; x++) {
            cin >> binary >> A >> B;
            
            if (binary == "AND") {
                array[x] = AND (A, B);
            }
            if (binary == "OR") {
                array[x] = OR (A, B);
            }
        }
    }
    
    if (type == 2) {
        for (int x = 0; x < 100; x++) {
            cin >> binary;
            
            if (binary == "0") {
                break;
            }
            
            cin >> A >> B;
            
            if (binary == "AND") {
                array[x] = AND (A, B);
            }
            if (binary == "OR") {
                array[x] = OR (A, B);
            }
            N++;
        }
    }
    
    if (type == 3) {
        while (cin >> binary) {
            
            cin >> A >> B;
            
         //      if (binary.empty()) {
         //          break;
         //      }
            
            if (binary == "AND") {
                array[y] = AND (A, B);
            }
            if (binary == "OR") {
                array[y] = OR (A, B);
            }
            N++;
            y++;
            
        }
    }
    
    for (int x = 0; x < N; x++) {
        cout << array[x] << endl;
    }
}