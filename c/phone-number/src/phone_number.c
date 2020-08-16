#include "phone_number.h"
#include <string.h>

char *phone_number_clean(const char *input)
{
    // remove all non-digit characters
    char* res = (char*)malloc(strlen(input) * sizeof(char));
    unsigned int i, count = 0;
    for(i = 0; i < strlen(input); i++)
    {
	if((48 <= input[i]) && (input[i] <= 57))
	{
	    char tmp = input[i];
	    res[i - count] = tmp;
	}
	else
	{
	    count++;
	}
    }
    res[i - count] = '\0';
    
    // check output for correct number formatting
    if((strlen(res) == 10) && (res[0] > 49) && (res[3] > 49))
    {
	return res;
    }
    else if((strlen(res) == 11) && (res[0] == '1'))
    {
	    for(unsigned int i = 0; i < 10; i++)
	    {
		char tmp = res[i + 1];
		res[i] = tmp;
	    }
	    res[10] = '\0';
	    return res;
    }
    else
    {
	res = realloc(res, 10 * sizeof(char));
	for(unsigned int i = 0; i < 10; i++)
	{
	    res[i] = '0';
	}
	res[10] = '\0';
	return res;
    }
}

