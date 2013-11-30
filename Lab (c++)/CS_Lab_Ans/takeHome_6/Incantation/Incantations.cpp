//
//  Incantations.cpp
//  helloworld
//
//  Created by Desmond  on 17/4/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "Incantations.h"
#include <vector>
#include <list>

using namespace std;

int hash1(string incantation) {
    int key = 0;
    for (int i=0; i<incantation.length(); ++i) {
        key += key*37 + incantation[i];
        key = key % Size;
    }
    return key % Size;
}

int hash2(int key) {
    int s = Size - 1;
    key = (key%s) + 1;
    return key;
}

void insert(Node table[], string incantation) {
    int key = hash1(incantation);
    
    while (table[key].getOccurance() != 0 && table[key].getString() != incantation) {
        key = (key + hash2(key)) % Size;
    }
    table[key].insertString(incantation);
}

int search(Node table[], string incantation) {
    int key = hash1(incantation);
    
    while (table[key].getOccurance() != 0 && table[key].getString() != incantation) {
        key = (key + hash2(key)) % Size;
    }
    return table[key].deleteOccurance();
}

/*
 search from the front of the vector. pop from the front till it has an unique
 incantation
 */
int deleteFront(int minLength, Node table[], list<string> list) {
    int length = minLength;
    
    while (search(table, list.front()) != 0) {
        length -= list.front().length();
        list.pop_front();
    }
    return length;
}

/*
 delete last element of the vector if it is not an unique incantation
 */
int deleteBack(int minLength, Node table[], list<string> list) {
    int length = minLength;
    
    while (search(table, list.back()) != 0) {
        length -= list.back().length();
        list.pop_back();
    }
    return length;
}

int findMinLength(int minLength, Node table1[], Node table2[], list<string> list1, list<string> list2) {
    int length1 = minLength, length2 = minLength;
    
    //delete from front first
    length1 = deleteFront(length1, table1, list1);
    length1 = deleteBack(length1, table1, list1);
    
    //delete from back first
    length2 = deleteBack(length2, table2, list2);
    length2 = deleteFront(length2, table2, list2);
    
    return min(length1,length2);
}

int main()
{
    int minLength = 0, N = 0;
    string incantation;
    list<string> list1, list2;
    Node table1[Size], table2[Size];
    
    for (int i=0; i<Size; ++i) {
        Node node;
        table1[i] = node;
        table2[i] = node;
    }
    
    cin >> N;
    
    while (N>0) {
        cin >> incantation;
        minLength += incantation.length();
        list1.push_back(incantation);
        list2.push_back(incantation);
        insert(table1, incantation);
        insert(table2, incantation);
        N--;
    }
    
    minLength = findMinLength(minLength, table1, table2, list1, list2);
}