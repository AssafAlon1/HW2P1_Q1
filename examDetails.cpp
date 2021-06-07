
// NAMESPACE???????????

#include "examDetails.h"


examDetails::examDetails(int course_id, int month, int day, int starting_hour,
                         int length, string zoom_link)
{
    // Verify Date
    if (month > 12 || month < 1 || day > 30 || day < 1) 
    {
        //throw 
    }

    // Verify Time
    if (length < 1) // ? edit this ? starting hour ?
    {
        // throw
    }

    // Verify General 
    //if () something else (zoom link / course_id / length)

    // Initialize fields
    this->course_id     = course_id;
    this->month         = month;
    this->day           = day;
    this->starting_hour = starting_hour;
    this->length        = length;
    this->zoom_link     = zoom_link;
}

string examDetails::getLink()
{
    return this->zoom_link;
}