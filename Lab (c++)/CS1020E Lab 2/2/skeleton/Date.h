/**********************
 *
 * Name: Ng Yang Yi Desmond 
 * Matric No: U095916B
 * Plab Account:
 *
 **********************/

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        // Constructors
    Date(int complete_day, int complete_month, int complete_year) {
        day = complete_day;
        year = complete_year;
        month = complete_month;
    }
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }
    
        // Setters and getters
    int getday() {return day;}
    int getmonth() {return month;}
    int getyear() {return year;}

        // Precondition:
        // Postcondition:
        int compare(Date otherDate);
};

#endif
