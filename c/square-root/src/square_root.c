#include "square_root.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int squareRoot(unsigned int S)
{
    double guess = 1.0;
    while((guess * guess) < S)
    {
	guess++;
    }
    double x0 = guess;
    double x1 = ((x0 + ((double)S / x0)) / 2);
    double diff = (x0 < x1) ? (x1 - x0) : (x0 - x1);
    while(diff > 0.0001)
    {
	// recursion
	x0 = x1;
	x1 = ((1 / 2) * (x1 + (S / x1)));
	diff = (x0 < x1) ? (x1 - x0) : (x0 - x1);
    }

    return (unsigned int)x1;
}

