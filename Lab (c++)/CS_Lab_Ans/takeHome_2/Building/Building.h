/**********************
 *
 * Name: Ng Yang Yi Desmond
 * Matric No: U095016B
 * Plab Account:
 *
 **********************/

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "Date.h"
using namespace std;

class Building
{
    private:
        string building_name;
        string location;
        Date opening_date;
    public:
        // Constructors
    Building(string name, string loco, Date open_date){
        building_name = name;
        location = loco;
        opening_date = open_date;
    }
        // Setters and getters
    string getname() {return building_name;}
    string getlocation() {return location;}
    Date getDate() {return opening_date;}
};

#endif

