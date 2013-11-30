//
//  Person.h
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//


#ifndef Person_h
#define Person_h

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Person{
    
private:
    
    string name;
    vector<int> groups;
    
public:
    
    //constructor
    Person();
    Person(string personName);
    
    //getters
    string getName();
    
    //functions & methods
    void joinGroup(int grp);
    void quitGroup(int grp);
    
    int getNumOfGroups();
    bool compareGroupID(Person *member);
};
#endif /* defined(__helloworld__Person__) */
