//
//  Query.cpp
//  helloworld
//
//  Created by Desmond  on 15/2/13.
//  Copyright (c) 2013 Desmond . All rights reserved.
//
#include "Query.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void Query::addAirLine(Airline newEntry)
{
    listAirline.push_back(newEntry);
}
 
vector<Airline> Query::earliestDepart(string frmCity, string to_City, SGTime currentTime) {
    vector<Airline> infoList;
    vector<Airline> earliest;
    
    for (int i=0; i != listAirline.size(); i++) {
        if (listAirline[i].getFromCity() == frmCity && listAirline[i].getToCity() == to_City) {
            infoList.push_back(listAirline[i]);
        }
    }
    for (int i=0; i != infoList.size(); i++) {
        if (earliest.empty()) {
            earliest.push_back(infoList[i]);
        }
        if (earliest[0].waitTime(currentTime) > infoList[i].waitTime(currentTime)) {
            earliest.clear();
            earliest.push_back(infoList[i]);
        }
    }
    return earliest;
}

vector<Airline> Query::earliestArrive(string frmCity, string to_City, SGTime currentTime) {
    vector<Airline> infoList;
    vector<Airline> earliest;
    
    for (int i=0; i != listAirline.size(); i++) {
        if (listAirline[i].getFromCity() == frmCity && listAirline[i].getToCity() == to_City) {
            infoList.push_back(listAirline[i]);
        }
    }
   
    for (int i=0; i != infoList.size(); i++) {
        if (earliest.empty()) {
            earliest.push_back(infoList[i]);
        }
        int totalTime_1 = earliest[0].diffCompare() + earliest[0].waitTime(currentTime);
        int totalTime_2 = infoList[i].diffCompare() + infoList[i].waitTime(currentTime);
        if (totalTime_1 > totalTime_2) {
            earliest.clear();
            earliest.push_back(infoList[i]);
        }        
    }
    return earliest;
}

vector<Airline> Query::shortFlight(string frmCity, string to_City, SGTime currentTime) {
    vector<Airline> infoList;
    vector<Airline> earliest;
    
    for (int i=0; i != listAirline.size(); i++) {
        if (listAirline[i].getFromCity() == frmCity && listAirline[i].getToCity() == to_City) {
            infoList.push_back(listAirline[i]);
        }
    }
    for (int i=0; i != infoList.size(); i++) {
        if (earliest.empty()) {
            earliest.push_back(infoList[i]);
        }
        if (earliest[0].diffCompare() > infoList[i].diffCompare()) {
            earliest.clear();
            earliest.push_back(infoList[i]);
        }
    }
    return earliest;
}

vector<Airline> Query::cheapest(string frmCity, string to_City, SGTime currentTime) {
    vector<Airline> infoList;
    vector<Airline> cheap;
    
    for (int i=0; i != listAirline.size(); i++) {
        if (listAirline[i].getFromCity() == frmCity && listAirline[i].getToCity() == to_City) {
            infoList.push_back(listAirline[i]);
        }
    }
    for (int i=0; i != infoList.size(); i++) {
        if (cheap.empty()) {
            cheap.push_back(infoList[i]);
        }
        if (cheap[0].getCost() > infoList[i].getCost()) {
            cheap.clear();
            cheap.push_back(infoList[i]);
        }
    }
    return cheap;
}

string convertString(int Hrs, int Mins) {
    ostringstream oss;
    if (Mins < 10) {
        oss << Hrs << ":" << 0 << Mins;
        return oss.str();
    } else
        oss << Hrs << ":" << Mins;
    return oss.str();
}

int main ()
{

    int N = 0; //no. of airlines
    int Q = 0; //no. of queries
    
    string frmCity = "";
    string to_City = "";
    int arriveDay = 0;
    int price = 0;
    
    Query airLineList;
    
    string depTime = "";
    string arrTime = "";
    
    int depHrs = 0;
    int depMins = 0;
    int arrHrs = 0;
    int arrMins = 0;
    
    cin >> N;
    
    while (N>0) {
        cin >> frmCity >> to_City >> depTime >> arriveDay >> arrTime >> price;
        
        
        //setting the time to integers
        if (depTime.length() == 5) {
            depHrs = (depTime.at(0) - 48)*10 + (depTime.at(1) - 48);
            depMins = (depTime.at(3) - 48)*10 + (depTime.at(4) - 48);
        } else if (depTime.length() == 4){
            depHrs = depTime.at(0) - 48;
            depMins = (depTime.at(2) - 48)*10 + (depTime.at(3) - 48);
        }
        
        if (arrTime.length() == 5) {
            arrHrs = (arrTime.at(0) - 48)*10 + (arrTime.at(1) - 48);
            arrMins = (arrTime.at(3) - 48)*10 + (arrTime.at(4) - 48);
        } else if (arrTime.length() == 4) {
            arrHrs = arrTime.at(0) - 48;
            arrMins = (arrTime.at(2) - 48)*10 + (arrTime.at(3) - 48);
        }
        
        SGTime departTime(depHrs, depMins);
        SGTime arriveTime(arrHrs, arrMins);
        
        // a new obj of class Airline is initialized
        Airline newEntry(frmCity, to_City, departTime, arriveTime, arriveDay, price);
        //add new entry into vector airlinelist
        airLineList.addAirLine(newEntry);
        N--;
    }
    
    int queryType = 0;
    string current_Time = "";
    int currentHrs = 0;
    int currentMins = 0;
    cin >> Q;
    
    while (Q>0) {
        cin >> queryType >> frmCity >> to_City >> current_Time;
        
        if (current_Time.length() == 5) {
            currentHrs = (current_Time.at(0) - 48)*10 + (current_Time.at(1) - 48);
            currentMins = (current_Time.at(3) - 48)*10 + (current_Time.at(4) - 48);
        } else if (current_Time.length() == 4) {
            currentHrs = current_Time.at(0) - 48;
            currentMins = (current_Time.at(2) - 48)*10 + (current_Time.at(3) - 48);
        }
        
        //setting current_Time to SGTime class
        SGTime currentTime(currentHrs, currentMins);
        
        //find earliest departure time
        if (queryType == 1) {
            vector<Airline> earliestFlight = airLineList.earliestDepart(frmCity, to_City, currentTime);
                
            depTime = convertString(earliestFlight[0].getDepartTime().getHours(), earliestFlight[0].getDepartTime().getMintues());
            arrTime = convertString(earliestFlight[0].getArriveTime().getHours(), earliestFlight[0].getArriveTime().getMintues());
                
            cout << earliestFlight[0].getFromCity() << " " << earliestFlight[0].getToCity() << " ";
            cout << depTime << " " << earliestFlight[0].getArrivalDay() << " " << arrTime << " " << earliestFlight[0].getCost() << endl;
        }
        //find earliest arrival time
        if (queryType == 2) {
            vector<Airline> earliestArrival = airLineList.earliestArrive(frmCity, to_City, currentTime);
            
            depTime = convertString(earliestArrival[0].getDepartTime().getHours(), earliestArrival[0].getDepartTime().getMintues());
            arrTime = convertString(earliestArrival[0].getArriveTime().getHours(), earliestArrival[0].getArriveTime().getMintues());
            
            cout << earliestArrival[0].getFromCity() << " " << earliestArrival[0].getToCity() << " ";
            cout << depTime << " " << earliestArrival[0].getArrivalDay() << " " << arrTime << " " << earliestArrival[0].getCost() << endl;
        }
        //find shortest flight time
        if (queryType == 3) {
            vector<Airline> shortestFlight = airLineList.shortFlight(frmCity, to_City, currentTime);
            
            depTime = convertString(shortestFlight[0].getDepartTime().getHours(), shortestFlight[0].getDepartTime().getMintues());
            arrTime = convertString(shortestFlight[0].getArriveTime().getHours(), shortestFlight[0].getArriveTime().getMintues());
            
            cout << shortestFlight[0].getFromCity() << " " << shortestFlight[0].getToCity() << " ";
            cout << depTime << " " << shortestFlight[0].getArrivalDay() << " " << arrTime << " " << shortestFlight[0].getCost() << endl;
        }
        //find cheapest flight
        if (queryType == 4) {
            vector<Airline> cheapestFlight = airLineList.cheapest(frmCity, to_City, currentTime);
            
            depTime = convertString(cheapestFlight[0].getDepartTime().getHours(), cheapestFlight[0].getDepartTime().getMintues());
            arrTime = convertString(cheapestFlight[0].getArriveTime().getHours(), cheapestFlight[0].getArriveTime().getMintues());
            
            cout << cheapestFlight[0].getFromCity() << " " << cheapestFlight[0].getToCity() << " ";
            cout << depTime << " " << cheapestFlight[0].getArrivalDay() << " " << arrTime << " " << cheapestFlight[0].getCost() << endl;
        }
        
        Q--;
    }
}