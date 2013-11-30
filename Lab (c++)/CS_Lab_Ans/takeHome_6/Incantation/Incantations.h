//
//  Incantations.h
//  helloworld
//
//  Created by Desmond  on 17/4/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef __helloworld__Incantations__
#define __helloworld__Incantations__

#include <iostream>
#include <string>

#define Size 2011

using namespace std;

class Node {
private:
    string incantation;
    int occurance;
public:
    //constructor
    Node();
    //method
    void insertString(string incantation);
    int deleteOccurance();
    //getter
    string getString() {return incantation;}
    int getOccurance() {return occurance;}
};

Node::Node() {
    this->incantation = " ";
    this->occurance = 0;
}

void Node::insertString(string incantation) {
    this->incantation = incantation;
    this->occurance += 1;
}

int Node::deleteOccurance() {
    occurance--;
    return occurance;
}

#endif /* defined(__helloworld__Incantations__) */
