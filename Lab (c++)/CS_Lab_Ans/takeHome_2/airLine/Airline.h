//
//  Airline.h
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef Airline__H
#define Airline__H

#include <string>
#include "SGTime.h"

using namespace std;

class Airline
{
private:
    string fromCity;
    string toCity;
    SGTime departureTime;
    SGTime arrivalTime;
    int arrivalDay;
    int cost;
public:
    //constructors
    Airline(string frmCity, string to_City, SGTime departTime, SGTime arriveTime, int arriveDay, int price) {
        fromCity = frmCity;
        toCity = to_City;
        departureTime = departTime;
        arrivalTime = arriveTime;
        arrivalDay = arriveDay;
        cost = price;
    }
    
    //destructor
    ~Airline() {}
    //getters
    string getFromCity() {return fromCity;}
    string getToCity() {return toCity;}
    SGTime getDepartTime() {return departureTime;}
    SGTime getArriveTime() {return arrivalTime;}
    int getArrivalDay() {return arrivalDay;}
    int getCost() {return cost;}
    
    //find time difference
    int diffCompare();
    
    //waiting time
    int waitTime(SGTime currentTime);
};

#endif /* defined(__helloworld__Airline__) */
