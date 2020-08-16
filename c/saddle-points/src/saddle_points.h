#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct saddle_point_t
{
    unsigned int row;
    unsigned int column;
} saddle_point_t;

typedef struct saddle_points_t
{
    unsigned int count;
    saddle_point_t* points;
} saddle_points_t;

saddle_points_t* saddle_points(unsigned int row,
			       unsigned int col,
			       uint8_t matrix[row][col]);

void free_saddle_points(saddle_points_t* actual);

#endif
