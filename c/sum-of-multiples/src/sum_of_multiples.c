#include "sum_of_multiples.h"

unsigned int sum_of_multiples(const unsigned int *multiples,
	const size_t number_of_multiples,
	const unsigned int up_to)
{
    if(!multiples)
    {
	return 0;
    }
    else
    {
	unsigned int count = 0;
	for(unsigned int i = 1; i < up_to; i++)
	{
	    unsigned int check = 0;
	    for(unsigned int j = 0; j < number_of_multiples; j++)
	    {
		unsigned int factor = multiples[j];
		if(factor && !(i % factor))
		{
		    check++;
		}
	    }
	    if(check)
	    {
		count += i;
	    }
	}
	return count;
    }
}

