#include "Date.h"

int Date::compare(Date otherDate)
{
    if (year < otherDate.getyear()) {
        return 1;
    } else if (year > otherDate.getyear()) {
        return -1;
    } else if (month < otherDate.getmonth()) {
        return 1;
    } else if (month > otherDate.getmonth()) {
        return -1;
    } else if (day < otherDate.getday()) {
        return 1;
    } else if (day > otherDate.getday()) {
        return -1;
    } else
        return 0;
}
