#include "examDetails.h"
#include <iostream>

using std::cout;
using std::endl;

int main ()
{
    cout << "hey" << endl;
    examDetails detail = examDetails(1, 1, 1, 1, 1, "Rick roll");
    string the_link = detail.getLink();
    cout << the_link;
}