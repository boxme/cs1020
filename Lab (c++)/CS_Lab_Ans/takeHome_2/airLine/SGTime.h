//
//  SGTime.h
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef SGTime__H
#define SGTime__H

#include <iostream>

using namespace std;

class SGTime
{
private:
    int hours;
    int minutes;
public:
    //constructors
    SGTime(int hrs, int mins) {
        hours = hrs;
        minutes = mins;
    }
    
    SGTime(){
        hours = 0;
        minutes = 0;
    }
    //destructor
    ~SGTime() {}
    
    //getters
    int getHours() {return hours;}
    int getMintues() {return minutes;}
    
    //time comparison
    int Compare(SGTime Time);
    
    //conversion to minutes
    int convert();
};

#endif /* defined(__helloworld__SGTime__) */
