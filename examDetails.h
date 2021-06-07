
// NAMESPACE???????????


#ifndef _EXAM_DETAILS_H
#define _EXAM_DETAILS_H

#include <string>
using std::string;

class examDetails
{
public:
    examDetails(int course_id, int month, int day, int starting_hour,  // STARTING HOUR CAN BE 15:30!!!
                int length, string zoom_link="");
    ~examDetails() =default;
    string getLink();
private:
    int course_id, month, day, starting_hour, length;
    string zoom_link;
};



#endif