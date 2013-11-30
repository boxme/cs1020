/**********************
 *
 * Name:
 * Matric No:
 * Plab Account:
 *
 **********************/

#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <string>
#include <vector>
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
        vector<Building> search(string keyword);

        // Precondition:
        // Postcondition:
        Building findOldestBuilding();

        // Precondition:
        // Postcondition:
        Building findNewestBuilding();
};

#endif