//
//  Query.h
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//

#ifndef Query__H
#define Query__H

#include "Airline.h"
#include "SGTime.h"
#include <vector>
#include <string>

using namespace std;

class Query
{
private:
    vector<Airline> listAirline;
public:
    //adding airline info
    void addAirLine(Airline newEntry);
    
    //find the earliest departure time
    vector<Airline> earliestDepart(string frmCity, string to_City, SGTime currentTime);
    
    //find earliest arrival time
    vector<Airline> earliestArrive(string frmCity, string to_City, SGTime currentTime);
    
    //find shortest flight
    vector<Airline> shortFlight(string frmCity, string to_City, SGTime currentTime);
    
    //cheapest flight
    vector<Airline> cheapest(string frmCity, string to_City, SGTime currentTime);
    
    //destructor
    ~Query() {}
};

#endif /* defined(__helloworld__Query__) */

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


