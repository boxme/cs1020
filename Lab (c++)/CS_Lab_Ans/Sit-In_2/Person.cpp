//
//  Person.cpp
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "Person.h"
#include <iostream>

Person::Person(){
    name = "";
    groups.push_back(0);
}

Person::Person(string personName) {
    name = personName;
    groups.push_back(0);
}

string Person::getName() {
    return this->name;
}

void Person::joinGroup(int grp) {
    int repeat = 0;
    for (int i=0; i != groups.size(); i++) {
        
        if (groups[i] == grp) {
            repeat++;
        }
    }
    if (repeat == 0) {
        groups.push_back(grp);
    }
}

void Person::quitGroup(int grp) {
    vector<int>::iterator iter;
    
    for (iter = groups.begin(); iter != groups.end(); ++iter) {
        if ((*iter) == grp) {
            groups.erase(iter);
            iter = groups.begin();
        }
    }
}

int Person::getNumOfGroups() {
    int NumOfGroups = 0;
    
    for (int i=0; i<groups.size(); i++) {
        NumOfGroups++;
    }
    return NumOfGroups;
}

bool Person::compareGroupID(Person *member) {
    
    for (int i=0; i<this->groups.size(); ++i) {
        for (int j=0; j<member->getNumOfGroups(); ++j) {
            if (this->groups[i] == member->groups[j]) {
                return true;
            }
        }
    }
    return false;
}


