//
//  SocialNetwork.cpp
//  helloworld
//
//  Created by Desmond  on 22/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#include "SocialNetwork.h"

SocialNetwork::SocialNetwork() {
    personsList = {};
    groupsList = {};
}

void SocialNetwork::addPerson(string personName, int grpID) {
    int repeat = 0;
    
    for (int i=0; i < personsList.size(); i++) {
        if (personsList[i]->getName() == personName) {
            personsList[i]->joinGroup(grpID);
            repeat++;
            break;
        }
    }
    
    if (repeat == 0) {
        personsList.push_back(new Person(personName));
//        personsList[personsList.size()-1]->joinGroup(grpID);
    }
}

int SocialNetwork::addGroup(string groupName, string personName){
    int id = 0;
    int repeat = 0;
    
    for (int i=0; i<groupsList.size(); i++) {
        if (groupsList[i]->getName() == groupName) {
            groupsList[i]->addMember(new Person(personName));
            repeat++;
            break;
        }
        id++;
    }
    
    if (repeat == 0) {
        groupsList.push_back(new Group(id, groupName));
        groupsList[groupsList.size()-1]->addMember(new Person(personName));
    }
    return id;
}

void SocialNetwork::quitGrp(string personName, int grpID){
    for (int i=0; i<personsList.size(); i++) {
        if (personsList[i]->getName() == personName) {
            personsList[i]->quitGroup(grpID);
        }
    }
}

void SocialNetwork::delMem(string personName, string groupName) {
    for (int i=0; i<groupsList.size(); i++) {
        if (groupsList[i]->getName() == groupName) {
            groupsList[i]->delMember(personName);
        }
    }
}

string SocialNetwork::answerQuery1() {
    string maxGrpName = "";
    int number = 0;
    
    if (groupsList.size() == 0) {
        return NULL;
    } else {
        maxGrpName = groupsList[number]->getName();
        for (int i=1; i<groupsList.size(); i++) {
            if ((groupsList[i]->getNumOfMembers()) > (groupsList[number]->getNumOfMembers())) {
                maxGrpName = groupsList[i]->getName();
                number = i;
            }
            if ((groupsList[i]->getNumOfMembers()) == (groupsList[number]->getNumOfMembers())) {
                if ((groupsList[i]->getName()) < (groupsList[number]->getName())) {
                    maxGrpName = groupsList[i]->getName();
                    number = i;
                }
            }
        }
    }
    return maxGrpName;
}

string SocialNetwork::answerQuery2() {
    vector<int> numOfFriends = {};
    int number = 0;
    string mostFriend = personsList[number]->getName();
    
    for (int i=0; i<personsList.size(); ++i) {
        int numFriends = 0;
        for (int j=0; j<personsList.size(); ++j) {
            if (i != j && personsList[i]->compareGroupID(personsList[j])) {
                numFriends++;
            }
        }
        
        numOfFriends.push_back(numFriends);
    }
    
    for (int i=1; i<numOfFriends.size(); ++i) {
        
        if (numOfFriends[i] > numOfFriends[number]) {
            mostFriend = personsList[i]->getName();
            number = i;
        }
        if (numOfFriends[i] == numOfFriends[number] && personsList[i]->getName() < personsList[number]->getName()) {
            mostFriend = personsList[i]->getName();
            number = i;
        }
    }
    return mostFriend;
}

int main () {
    int N, queryNum;
    string action, personName, groupName;
    SocialNetwork netWork;
    
    cin >> N;
    
    while (N > 0) {
        cin >> action;
        if (action == "Query") {
            cin >> queryNum;
        } else {
            cin >> personName >> groupName;
        }
        //create & join
        if (action == "Createjoin") {
            int grpID = netWork.addGroup(groupName, personName);
            netWork.addPerson(personName, grpID);
        }
        //quit group
        if (action == "Quit") {
            int grpID = netWork.addGroup(groupName, personName);
            netWork.quitGrp(personName, grpID);
            netWork.delMem(personName, groupName);
        }
        //Query 1 & 2
        if (action == "Query") {
            if (queryNum == 1) {
                cout << netWork.answerQuery1() << endl;
            } else {
                cout << netWork.answerQuery2() << endl;
            }
        }
        N--;
    }
}