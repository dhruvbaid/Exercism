#include "pythagorean_triplet.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int* t(unsigned int a, unsigned int total)
{
    unsigned int* res = (unsigned int*)malloc(3 * sizeof(unsigned int));

    if(a <= total/3.0)
    {
	for(unsigned int b = a; b <= (total - a); b++)
	{
	    int c = total - a - b;
	    if(c > 0)
	    {
		unsigned int c2 = (unsigned int)c;
		if((c2 >= a) && (c2 >= b) && ((a * a) + (b * b) == (c2 * c2)))
		{
		    res[0] = a;
		    res[1] = b;
		    res[2] = c2;
		    return res;
		}
	    }
	}
    }

    return NULL;
}

triplets_t *triplets_with_sum(unsigned int sum)
{
    // obtain the number of triplets with the given sum
    unsigned int count = 0;
    for(unsigned int a = 1; a < ((sum / 3.0) + 1); a++)
    {
	unsigned int* tmp = t(a, sum);
	if(tmp)
	{
	    count++;
	    free(tmp);
	}
    }
    
    // define the structure which will contain the result
    triplets_t* res = (triplets_t*)malloc(sizeof(triplets_t));

    // update number of triples with given sum in result
    res->count = count;

    printf("There are %d triplets with sum %d\n", count, sum);
    
    // create list of triplets
    unsigned int** ts = (unsigned int**)malloc(count * sizeof(unsigned int*));
    for(unsigned int i = 0; i < count; i++)
    {
	ts[i] = (unsigned int*)malloc(3 * sizeof(unsigned int));
    }

    count = 0;
    for(unsigned int a = 1; a < ((sum / 3.0) + 1); a++)
    {
	unsigned int* tmp_triple = t(a, sum);
	if(tmp_triple)
	{
	    unsigned int* t = (unsigned int*)malloc(3 * sizeof(unsigned int));
	    t[0] = tmp_triple[0];
	    t[1] = tmp_triple[1];
	    t[2] = tmp_triple[2];

	    ts[count] = t;
	    count++;
	}
	free(tmp_triple);
    }

    triplet_t* triplets = (triplet_t*)malloc(count * sizeof(triplet_t));
    for(unsigned int i = 0; i < count; i++)
    {
	unsigned int* tmp = ts[i];
	triplets[i].a = tmp[0];
	triplets[i].b = tmp[1];
	triplets[i].c = tmp[2];
    }
    
    // feed list of triplets to the struct
    res->triplets = triplets;

    return res;
}

void free_triplets(triplets_t* triplets)
{
    free(triplets);
}
