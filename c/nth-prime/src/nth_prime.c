#include "nth_prime.h"
#include <math.h>

unsigned char isPrime(unsigned int p)
{
    for(unsigned int f = 2; f < (floor((double)sqrt(p)) + 1); f++)
    {
	if(!(p % f))
	{
	    return 0;
	}
    }
    return 1;
}

uint32_t nth(uint32_t n)
{
    if(n == 0)
    {
	return 0;
    }
    else if(n == 1)
    {
	return 2;
    }
    else
    {
	unsigned int count = 1;
	unsigned int p = 3;
	while(count < n)
	{
	    if(isPrime(p))
	    {
		count++;
		p++;
	    }
	    else
	    {
		p++;
	    }
	}
	return p-1;
    }
}
