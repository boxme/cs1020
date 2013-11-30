#include "SearchEngine.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

bool SearchEngine::addBuilding(string building_name, string location, Date
        opening_date)
{
    Building listEntry(building_name, location, opening_date);
    for (int i=0; i<listOfBuilding.size(); i++) {
        string temp_name = listOfBuilding[i].getname();
        if (temp_name == building_name) {
        return false;
        }
    } 
    listOfBuilding.push_back(listEntry);
    return true;
}

vector<string> SearchEngine::search(string keyword)
{
    vector<string> vectName;
    for (int i=0; i<listOfBuilding.size(); i++) {
        
        string temp_name = listOfBuilding[i].getname();
        for (int j=0; j<temp_name.size(); j++) {
            temp_name.at(j) = tolower(temp_name.at(j));
        }
        for (int j=0; j<keyword.size(); j++) {
            keyword.at(j) = tolower(keyword.at(j));
        }
        if ((temp_name.find(keyword, 0) != string::npos)) {
            vectName.push_back(listOfBuilding[i].getname());
        }
    }
    return vectName;
}

int main() {
    // create a search engine object
    string building_name, loco, gregorian_month;
    int complete_day, complete_year, complete_month;
    string action, temp;
    string newest[2] = {""};
    string oldest[2] = {""};
    
    SearchEngine list;
    Date oldestDate;
    Date newestDate;
    
    vector<string> searchName;
    string calendar[13] = {"empty", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    int Q = 0;
    cin >> Q;
    
    while (Q != 0) {
        
        cin >> action;
        if (action == "add") {
            cin >> building_name >> loco >> complete_day >>  gregorian_month >> complete_year;
        }
        if (action == "search") {
            cin >> building_name;
        }
        
        for (int i=1; i<13; i++) {
            if (calendar[i] == gregorian_month) {
                complete_month = i;
                break;
            }
        }
        
        if (action == "add") {
            Date opening_date(complete_day, complete_month, complete_year);
            if (oldestDate.getyear() == 0) {
                oldestDate = opening_date;
                oldest[0] = building_name;
                oldest[1] = loco;
            }
            if (newestDate.getyear() == 0) {
                newestDate = opening_date;
                newest[0] = building_name;
                newest[1] = loco;
            }
            if (list.addBuilding(building_name, loco, opening_date)) {
                cout << "Added" << endl;
                if (opening_date.compare(oldestDate) == 1){
                   oldest[0] = building_name;
                   oldest[1] = loco;
                   oldestDate = opening_date;
                } else if (opening_date.compare(newestDate) == -1) {
                    newest[0] = building_name;
                    newest[1] = loco;
                    newestDate = opening_date;
                } 
            } else
                cout << "Duplicated" << endl;
        }
        if (action == "search") {
            string keyword = building_name;
            searchName = (list.search(keyword));
            
            for (int i=0; i<searchName.size(); i++) {
                if (i == (searchName.size()-1)) {
                    cout << searchName[i] << endl;
                } else {
                    cout << searchName[i] << ", ";
                }
            }
        }
        if (action == "oldest") {
            cout << oldest[0] << " in " << oldest[1] << endl;
        }
        if (action == "newest") {
            cout << newest[0] << " in " << newest[1] << endl;
        }
        Q--;
    }

    return 0;
}
