/**********************
 *
 * Name: Ng Yang Yi Desmond
 * Matric No: U095916B
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
    Building (string build_name, string loca, Date completion_date) : building_name(build_name), location(loca), opening_date(completion_date) {}
        // Setters and getters
    
};

#endif
