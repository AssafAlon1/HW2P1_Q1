#ifndef _EXAM_DETAILS_H
#define _EXAM_DETAILS_H

#include <string>
using std::string;


namespace mtm
{
    class ExamDetails
    {
    public:
        ExamDetails(int course_id, int month, int day, double starting_hour, 
                    int length, string zoom_link="");
        ExamDetails(const ExamDetails& sourceExamDetails) = default;
        ExamDetails& operator=(const ExamDetails& exam_details) = default;
        ~ExamDetails() = default;
        string getLink();
        void setLink(const string new_link);
        int operator-(const ExamDetails& exam_details) const;
        bool operator<(const ExamDetails& exam_details) const;
        static ExamDetails makeMatamExam();

        class InvalidDateException {};
        class InvalidTimeException {};
        class InvalidArgsException {};

    private:
        int course_id, month, day, length;
        int starting_hour, starting_minute;
        string zoom_link;

        static const int FIRST_DAY       = 1;
        static const int DAYS_IN_MONTH   = 30;
        static const int MIN_MONTH       = 1;
        static const int MAX_MONTH       = 12;
        static const int HALF_AN_HOUR    = 30;
        static const int MINUTES_IN_HOUR = 60;
        static const int HOURS_IN_DAY    = 24;
        static const double EPSILON;

        static const int MTM_COURSE_ID    = 234124;
        static const int MTM_DAY          = 28;
        static const int MTM_MONTH        = 7;
        static const int MTM_LENGTH       = 3;
        static const double MTM_HOUR;
        static const string MTM_LINK;

        static bool isHourValid(double starting_hour);
        static void verifyInput(int course_id, int month, int day,
                    double starting_hour, int length, string zoom_link);
        
        friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam_details);
    };
}
#endif