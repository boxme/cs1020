/**********************
 *
 * Name: Ng Yang Yi Desmond
 * Matric No: U095916B
 * Plab Account:
 *
 **********************/

#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <string>
#include <vector>
#include "Date.h"
#include "Building.h"

using namespace std;

class SearchEngine
{
    private:
        vector<Building> listOfBuilding;
    public:
        // Precondition:
        // Postcondition:
        bool addBuilding(string building_name, string location, Date
        opening_date);

        // Precondition:
        // Postcondition:
        vector<string> search(string keyword);
};

#endif