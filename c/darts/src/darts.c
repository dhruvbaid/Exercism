#include "darts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int score(coordinate_t pos)
{
    float x = pos[0];
    float y = pos[1];

    float dist = sqrt((x * x) + (y * y));


    if(dist <= 1.0)
    {
	return 10;
    }
    else if(dist <= 5.0)
    {
	return 5;
    }
    else if(dist <= 10.0)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
