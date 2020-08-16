#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool is_armstrong_number(int n)
{
    unsigned int numDigits = 0;
    unsigned int x = n;
    while(x > 0)
    {
	x = (int)(n / pow(10.0, (double)numDigits));
	numDigits++;
    }
    if(numDigits > 0)
    {
	numDigits--;
    }
    x = n;
    
    unsigned int count = 0;
    for(int i = numDigits - 1; i >= 0; i--)
    {
	char d = (int)(n / pow(10.0, (double)i));
	count += (int)pow((double)d, (double)numDigits);
	n -= (int)pow(10.0, (double)i) * d;
    }

    if(count == x)
    {
	return true;
    }
    else
    {
	return false;
    }
}
