#include "crypto_square.h"
#include <string.h>

char *ciphertext(const char *input)
{
    // clean input
    char* cleaned = (char*)malloc(strlen(input) * sizeof(char));
    unsigned int i, count = 0;
    for(i = 0; i < strlen(input); i++)
    {
	if(((97 <= input[i]) && (input[i] <= 122)) ||
	   ((48 <= input[i]) && (input[i] <= 57)))
	{
	    // small letter or digit
	    char tmp = input[i];
	    cleaned[i - count] = tmp;
	}
	else if((65 <= input[i]) && (input[i] <= 90))
	{
	    // capital letter - convert to lowercase first
	    char tmp = input[i] + 32;
	    cleaned[i - count] = tmp;
	}
	else
	{
	    // punctuation
	    count++;
	}
    }
    cleaned[i - count] = '\0';
    
    // calculate number of rows and columns in the square
    unsigned int len = strlen(cleaned);

    unsigned int r = 1;
    unsigned int c1 = 1, c2 = 2;
    while(((r * c1) < len) && ((r * c2) < len))
    {
	r++;
	c1 = r;
	c2 = r + 1;
    }
    unsigned int c = ((r * c1) >= len) ? c1 : c2;

    // encrypt text
    char* encrypted = (char*)malloc((r + 1) * c * sizeof(char));
    count = 0;
    for(unsigned int col = 0; col < c; col++)
    {
	for(unsigned int row = 0; row < r; row++)
	{
	    unsigned int index = col + (row * c);
	    if(index < len)
	    {
		char tmp = cleaned[index];
		encrypted[count] = tmp;
		count++;
	    }
	    else
	    {
		encrypted[count] = ' ';
		count++;
	    }
	}
	encrypted[count] = ' ';
	count++;
    }
    encrypted[strlen(encrypted) - 1] = '\0';

    if(!strlen(input))
    {
	encrypted = realloc(encrypted, sizeof(char));
	encrypted[0] = '\0';
    }
    
    return encrypted;
}

