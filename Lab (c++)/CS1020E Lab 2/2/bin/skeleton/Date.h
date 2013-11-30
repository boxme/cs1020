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
    Date (int complete_day, int complete_month, int complete_year) : day(complete_day), month(completE_month), year(complete_year) {}
        // Setters and getters

        // Precondition:
        // Postcondition:
        int compare(Date date);
};

int Date::compare (Date date)
{
    
}

#endif
