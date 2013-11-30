//
//  Group.h
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef Group_h
#define Group_h

#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Group{
    
private:
    
    int id;
    string name;
    vector<Person*> members;
    
public:
    
    //constructors
    Group();
    Group(int id, string groupName);
    
    //getters
    int getId();
    string getName();
    
    //functions
    void addMember(Person *p);
    void delMember(string memberName);
    int getNumOfMembers();
    
};
#endif /* defined(__helloworld__Group__) */
