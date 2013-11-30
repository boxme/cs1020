//
//  Group.cpp
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "Group.h"

Group::Group() {
    id = 0;
    name = "";
    members = {};
}

Group::Group(int id, string groupName) {
    this->id = id;
    name = groupName;
    members = {};
}

int Group::getId(){
    return id;
}

string Group::getName(){
    return name;
}

int Group::getNumOfMembers(){
    int numOfMember = 0;
    
    for (int i=0; i < members.size(); i++) {
        numOfMember++;
    }
    return numOfMember;
}

void Group::addMember(Person *p) {
    int repeat = 0;
    for (int i=0; i < members.size(); i++) {
        if ((members[i])->getName() == p->getName()) {
            repeat++;
        }
    }
    if (repeat == 0) {
        members.push_back(p);
    }
}

void Group::delMember(string memberName) {
    vector<Person*>::iterator iter;
    
    for (iter = members.begin(); iter != members.end(); ++iter) {
        if ((*iter)->getName() == memberName) {
            members.erase(iter);
            iter = members.begin();
        }
    }
}