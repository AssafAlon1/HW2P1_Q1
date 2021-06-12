#include "examDetails.h"
#include <iostream>

using std::endl;

namespace mtm
{
    // Defining non-int magic numbers
    const std::string ExamDetails::MTM_LINK = "https://tinyurl.com/59hzps6m";
    const double      ExamDetails::MTM_HOUR = 13;
    const double      ExamDetails::EPSILON  = 0.000001;

    // Verify the hour is valid
    bool ExamDetails::isHourValid(double starting_hour)
    {
        // Verify Time - hour is whithin the range 0:00-23:59
        if (starting_hour < 0 || starting_hour >= ExamDetails::HOURS_IN_DAY)
        {
            return false;
        }

        // Verify time - hour is xx:00 or xx:30
        double fraction = starting_hour - int(starting_hour);
        const double half     = double(HALF_AN_HOUR)/double(MINUTES_IN_HOUR);
        if ((fraction < EPSILON) || (fraction < half+EPSILON && fraction > half-EPSILON))
        {
            return true;
        }
        return false;
    }


    // Verify input for ExamDetail creation
    void ExamDetails::verifyInput(int course_id, int month, int day,
                    double starting_hour, int length, string zoom_link)
    {
        // Verify Date
        if (month > MAX_MONTH || month < MIN_MONTH || day > DAYS_IN_MONTH || day < FIRST_DAY) 
        {
            throw InvalidDateException();
        }


        // Verify Time
        if (!isHourValid(starting_hour) || length < 1) // @540
        {
            throw InvalidTimeException();
        }

        // Verify General 
        // if (course_id < 0) // @531
        // {
        //     throw InvalidArgsException();
        // }
    }


    // Constructor
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

    // Minus operator - difference in days
    int ExamDetails::operator-(const ExamDetails& exam_details) const
    {
        int month_difference = (this->month) - (exam_details.month);
        int days_difference  = (this->day)   - (exam_details.day);
        return month_difference*DAYS_IN_MONTH + days_difference;
    }
    
    // Less than operator - compares dates
    bool ExamDetails::operator<(const ExamDetails& exam_details) const
    {
        // Exams aren't on the same day - can determine which is first
        int days_difference = *this - exam_details;
        if (days_difference != 0)
        {
            return days_difference < 0;
        }

        // Exams are on the same day but aren't on the same hour
        int starting_hour_difference = (this->starting_hour) - (exam_details.starting_hour);
        if (starting_hour_difference != 0)
        {
            return starting_hour_difference > 0;
        }
        
        // Exams on the same hour, determine by minutes
        return this->starting_minute > exam_details.starting_minute;
    }

    string ExamDetails::getLink() const
    {
        return this->zoom_link;
    }

    void ExamDetails::setLink(const string new_link)
    {
        this->zoom_link = new_link;
    }

    // Print exam as requested
    std::ostream& operator<<(std::ostream& os, const ExamDetails& exam_details)
    {
        os << "Course Number: " << exam_details.course_id << endl;
        os << "Time: " << exam_details.day << "." << exam_details.month << " at ";
        os << exam_details.starting_hour << ":";

        // Printing extra 0 in minutes if needed
        if (exam_details.starting_minute < 10)
        {
            os << "0";
        }
        os << exam_details.starting_minute << endl;
        os << "Duration: "  << exam_details.length << ":00" << endl;
        os << "Zoom link: " << exam_details.zoom_link << endl;

        return os;
    }

    // Makes a matam test
    ExamDetails ExamDetails::makeMatamExam()
    {
        return ExamDetails(MTM_COURSE_ID, MTM_MONTH, MTM_DAY, MTM_HOUR,
                           MTM_LENGTH, MTM_LINK);
    }
}