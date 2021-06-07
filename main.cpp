#include "examDetails.h"
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;
using mtm::ExamDetails;

void my_exit (string err)
{
    cout << "INVALID " << err  << " NOT HANDLED, ABORTING" << endl;
    exit(1);
}

void dateTimeArgsTests()
{
    // Month is 13
    try {
        ExamDetails detail_invalid_month = ExamDetails(104031, 13, 15, 8.5, 3);
        my_exit("DATE");
    }
    catch (ExamDetails::InvalidDateException){}
    catch (...)
    {
        my_exit("DATE");
    }

    // Day is 32
    try {
        ExamDetails detail_invalid_day = ExamDetails(104031, 11, 32, 8.5, 3);
        my_exit("DATE");
    }
    catch (ExamDetails::InvalidDateException){}
    catch (...)
    {
        my_exit("DATE");
    }

    // Hour is 30
    try {
        ExamDetails detail_invalid_hour1 = ExamDetails(104031, 11, 29, 30, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }
    
    // Hour is 25.5
    try {
        ExamDetails detail_invalid_hour2 = ExamDetails(104031, 11, 29, 25.5, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }

    // Hour is 24
    try {
        ExamDetails detail_invalid_hour3 = ExamDetails(104031, 11, 24, 30, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }

    // Hour is 12.35
    try {
        ExamDetails detail_invalid_hour4 = ExamDetails(104031, 11, 29, 12.35, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }


     // Hour is 12.5001
    try {
        ExamDetails detail_invalid_hour4 = ExamDetails(104031, 11, 29, 12.5001, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }

    // Course id is negative
    try {
        ExamDetails detail_invalid_args1 = ExamDetails(-3, 11, 29, 12.5, 3);
        my_exit("ARGS");
    }
    catch (ExamDetails::InvalidArgsException){}
    catch (...)
    {
        my_exit("ARGS");
    }
    

}


int main ()
{
    cout << "Running basic ExamDetails tests... ";
    ExamDetails detail1 = ExamDetails(234125, 7, 5, 8, 3, "https://inverse.esrevni");
    ExamDetails detail2 = ExamDetails(104032, 7, 11, 9.5, 3, "https://log.sin.x");
    ExamDetails detail3 = ExamDetails(114071, 7, 15, 10, 3, "http://apple.com");
    ExamDetails detail4 = ExamDetails(234141, 7, 23, 12.5, 2, "https://eitan.ya.combi.co.il");
    //ExamDetails detail5 = ExamDetails::makeMatamExam();
    ExamDetails detail6 = ExamDetails(1000, 8, 5, 7.5, 4, "you are fake news");
    
    assert(detail2 - detail1 == 6);
    assert(detail1 - detail2 == -6);
    assert(detail3 - detail1 == 10);
    assert(detail3 - detail2 == 4);
    assert(detail6 - detail1 == 30);
    assert(detail1 - detail6 == -30);
    assert(detail6 - detail2 == 24);
    assert(detail2 - detail6 == -24);
    assert(detail1 < detail2);
    assert(detail2 < detail3);
    assert(detail1 < detail3);
    assert(detail3 < detail4);
    assert(detail2 < detail4);
    assert(detail1 < detail4);
    //assert(detail5 < detail4);
    //assert(detail5 < detail3);
    //assert(detail5 < detail2);
    //assert(detail5 < detail1);

    assert(detail1.getLink() == "https://inverse.esrevni");
    assert(detail3.getLink() == "http://apple.com");

    cout << "[OK]" << endl ;
    cout << "Running extra ExamDetails tests... " << endl ;

    dateTimeArgsTests();

    ExamDetails detail_empty_str = ExamDetails(104031, 4, 15, 8.5, 3);
    ExamDetails detail_midnight_exam = ExamDetails(1001, 3, 4, 0, 5, "https://link");
    
    cout << detail1 << endl << detail2 << endl << detail3 << endl << detail4 << endl /*<< detail1 << endl*/;

    cout << "[OK]" << endl;
    return 0;
}