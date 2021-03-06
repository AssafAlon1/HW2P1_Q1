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


     // Hour is 12.50001
    try {
        ExamDetails detail_invalid_hour4 = ExamDetails(104031, 11, 29, 12.50001, 3);
        my_exit("TIME");
    }
    catch (ExamDetails::InvalidTimeException){}
    catch (...)
    {
        my_exit("TIME");
    }

     // Hour is 12.500001
    ExamDetails valid_hour1 = ExamDetails(104031, 11, 29, 12.500001, 3);
    // Course id is negative
    // try {
    //     ExamDetails detail_invalid_args1 = ExamDetails(-3, 11, 29, 12.5, 3);
    //     my_exit("ARGS");
    // }
    // catch (ExamDetails::InvalidArgsException){}
    // catch (...)
    // {
    //     my_exit("ARGS");
    // }


}


int main ()
{
    cout << "Running basic ExamDetails tests... ";
    ExamDetails detail1 = ExamDetails(234125, 7, 5, 8, 3, "https://inverse.esrevni");
    ExamDetails detail2 = ExamDetails(104032, 7, 11, 9.5, 3, "https://log.sin.x");
    ExamDetails detail3 = ExamDetails(114071, 7, 15, 10, 3, "http://apple.com");
    ExamDetails detail4 = ExamDetails(234141, 7, 23, 12.5, 2, "https://eitan.ya.combi.co.il");
    ExamDetails detail5 = ExamDetails::makeMatamExam();
    ExamDetails detail6 = ExamDetails(1000, 8, 5, 7.5, 4, "you are fake news");
    
    assert(detail2 - detail1 == 6);
    assert(detail1 - detail2 == -6);
    assert(detail3 - detail1 == 10);
    assert(detail3 - detail2 == 4);
    assert(detail6 - detail1 == 30);
    assert(detail1 - detail6 == -30);
    assert(detail6 - detail2 == 24);
    assert(detail2 - detail6 == -24);
    assert(detail4 - detail5 == -5);
    assert(detail5 - detail4 == 5);
    assert(detail1 < detail2);
    assert(detail2 < detail3);
    assert(detail1 < detail3);
    assert(detail3 < detail4);
    assert(detail2 < detail4);
    assert(detail1 < detail4);
    assert(detail4 < detail5);
    assert(detail3 < detail5);
    assert(detail2 < detail5);
    assert(detail1 < detail5);

    assert(detail1.getLink() == "https://inverse.esrevni");
    assert(detail3.getLink() == "http://apple.com");

    cout << "[OK]" << endl ;




    cout << "Running extra ExamDetails tests... " << endl ;

    dateTimeArgsTests();

    // Copy constructor
    ExamDetails d1 = ExamDetails(detail1);
    assert(!(d1 < detail1 || detail1 < d1));
    cout << d1 << endl << endl << endl; 

    // Assignment operator
    ExamDetails d2 = detail2;
    assert(!(d2 < detail2 || detail2 < d2));
    cout << d2 << endl << endl << endl; 

    d1.setLink("trash");
    d2.setLink("trash");
    cout << d1 << detail1 << endl << endl << endl;
    cout << d2 << detail2 << endl << endl << endl; 

    ExamDetails detail_empty_str = ExamDetails(104031, 4, 15, 8.5, 3);
    ExamDetails detail_midnight_exam = ExamDetails(1001, 3, 4, 0, 5, "https://link");
    
    cout << detail1 << endl << detail2 << endl << detail3 << endl << detail4 << endl /*<< detail1 << endl*/;
    cout << detail_empty_str << endl << detail_midnight_exam << endl;
    cout << "[OK]" << endl;
    return 0;
}