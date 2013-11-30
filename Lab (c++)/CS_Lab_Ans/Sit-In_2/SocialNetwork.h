//
//  SocialNetwork.h
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef SocialNetwork_h
#define SocialNetwork_h

#include "Person.h"
#include "Group.h"
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

class SocialNetwork{
    
private:
    
    vector<Group *> groupsList;
    vector<Person *> personsList;
    
public:
    
    SocialNetwork();
    
    void addPerson(string personName, int grpID);
    int addGroup(string groupName, string personName);
    
    void quitGrp(string personName, int grpID);
    void delMem(string personName, string groupName);
    
    string answerQuery1();
    string answerQuery2();
    
};
#endif /* defined(__helloworld__SocialNetwork__) */
