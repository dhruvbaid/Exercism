#include "saddle_points.h"

saddle_points_t* saddle_points(unsigned int row,
			       unsigned int col,
			       uint8_t matrix[row][col])
{
    // allocate memory for the results
    saddle_points_t* res = (saddle_points_t*)malloc(sizeof(saddle_points_t));
    saddle_point_t* p = NULL;

    // num_points represents the number of saddle points found
    unsigned int num_points = 0;
    
    // only perform checks if there are a valid number of rows and columns
    if(row && col)
    {
	for(unsigned int r = 0; r < row; r++)
	{
	    for(unsigned int c = 0; c < col; c++)
	    {
		uint8_t curr = matrix[r][c];
		
		/* x and y represent the number of elements in curr's
		 * row and column which are <= or >= curr respectively
		 */
		unsigned int x = 0;
		unsigned int y = 0;

		// check entire row
		for(unsigned int i = 0; i < col; i++)
		{
		    if(curr >= matrix[r][i])
		    {
			x++;
		    }
		}
		// check entire column
		for(unsigned int j = 0; j < row; j++)
		{
		    if(curr <= matrix[j][c])
		    {
			y++;
		    }
		}

		if((x == col) && (y == row))
		{
		    // saddle point found
		    num_points++;
		    p = realloc(p, num_points * sizeof(saddle_point_t));
		    saddle_point_t tmp = {r+1, c+1};
		    p[num_points - 1] = tmp;
		}
	    }
	}
    }

    res->count = num_points;
    res->points = p;

    return res;
}

void free_saddle_points(saddle_points_t* actual)
{
    free(actual->points);
    free(actual);
}
