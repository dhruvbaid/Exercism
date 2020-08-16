#include "resistor_color.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char color_code(resistor_band_t col)
{
    return col;
}

unsigned int* colors()
{
    unsigned int* res = (unsigned int*)malloc(sizeof(unsigned int) * 9);
    for(unsigned int i = 0; i < 10; i++)
    {
	res[i] = i;
    }
    return res;
}
