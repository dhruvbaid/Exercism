#include "leap.h"

bool is_leap_year(int year)
{
    return ((!(year % 400)) || ((!(year % 4)) && (year % 100))) ? true : false;
}

