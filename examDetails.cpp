#include "examDetails.h"
#include <iostream>

using std::endl;
namespace mtm
{
    void ExamDetails::verifyInput(int course_id, int month, int day,
                    double starting_hour, int length, string zoom_link)
    {
        // Verify Date
        if (month > MAX_MONTH || month < MIN_MONTH || day > DAYS_IN_MONTH || day < FIRST_DAY) 
        {
            throw InvalidDateException();
        }

        // Verify Time - hour is whithin the range 0:00-23:59
        if (starting_hour < 0 || starting_hour > 24)
        {
            throw InvalidTimeException();
        }

        // Verify Time - hour is a multiply of 0.5
        double fraction = starting_hour - int(starting_hour);
        if ((fraction != 0 && fraction != 0.5) || length < 1) // @540
        {
            throw InvalidTimeException();
        }

        // Verify General 
        if (course_id < 0) // @531
        {
            throw InvalidArgsException();
        }
    }



    ExamDetails::ExamDetails(int course_id, int month, int day, double starting_hour,
                            int length, string zoom_link)
    {
        // Verifies input, throws in case if invalid input
        verifyInput(course_id, month, day, starting_hour, length, zoom_link);

        // Initialize fields
        this->course_id       = course_id;
        this->month           = month;
        this->day             = day;
        this->length          = length;
        this->zoom_link       = zoom_link;
        this->starting_hour   = int(starting_hour);
        
        // Only valid stating minutes are 0 or HALF_AN_HOUR (30)
        this->starting_minute = 0;
        if (starting_hour > int(starting_hour))
        {
            this->starting_minute = HALF_AN_HOUR;
        }
    }
    
    // ExamDetails::ExamDetails(const ExamDetails& sourceExamDetails) :
    //                          course_id(sourceExamDetails.course_id) , month(sourceExamDetails.month) , 
    //                          day(sourceExamDetails.day) , starting_hour(sourceExamDetails.starting_hour) , 
    //                          length(sourceExamDetails.length) , zoom_link(sourceExamDetails.zoom_link)
    // {}

    // ExamDetails& ExamDetails::operator=(const ExamDetails& exam_details)
    // {

    // }

    int ExamDetails::operator-(const ExamDetails& exam_details) const
    {
        int month_difference = (this->month) - (exam_details.month);
        int days_difference  = (this->day)   - (exam_details.day);
        return month_difference*DAYS_IN_MONTH + days_difference;
    }
    
    bool ExamDetails::operator<(const ExamDetails& exam_details) const
    {
        int days_difference = *this - exam_details;
        if (days_difference < 0)
        {
            return true;
        }

        if (days_difference > 0)
        {
            return false;
        }

        // Exams on the same day
        int starting_hour_difference = (this->starting_hour) - (exam_details.starting_hour);
        if (starting_hour_difference > 0)
        {
            return true;
        }

        if (starting_hour_difference < 0)
        {
            return false;
        }
        
        // Exams on the same hour
        return this->starting_minute > exam_details.starting_minute;
    }

    string ExamDetails::getLink()
    {
        return this->zoom_link;
    }

    void ExamDetails::setLink(string new_link)
    {
        this->zoom_link = new_link;
    }


    std::ostream& operator<<(std::ostream& os, const ExamDetails& exam_details)
    {
        os << "Course Number: " << exam_details.course_id << endl;
        os << "Time: " << exam_details.day << "." << exam_details.month << " at ";
        os << exam_details.starting_hour << ":";

        if (exam_details.starting_minute < 10)
        {
            os << "0";
        }
        os << exam_details.starting_minute << endl;
        os << "Duration: "  << exam_details.length << ":00" << endl;
        os << "Zoom link: " << exam_details.zoom_link << endl;

        return os;
    }

    // static ExamDetails makeMatamExam()
    // {
    //     return ExamDetails()
    // }
}