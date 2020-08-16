#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if(!phrase)
    {
	return false;
    }
    else if(phrase[0] == '\0')
    {
	return true;
    }
    else
    {
	// define placeholders for testing letters
	char char1, char2;

	// loop through all letters in phrase to test for equality
	unsigned int i = 0;
	while(phrase[i])
	{
	    // only perform checks if character is a letter to begin with
	    if(((phrase[i] >= 65) && (phrase[i] <= 90)) ||
	       ((phrase[i] >= 97) && (phrase[i] <= 122)))
	    {
		unsigned int j = i + 1;
		while(phrase[j])
		{
		    char1 = phrase[i];
		    char2 = phrase[j];
		    // convert both characters to lowercase
		    if((char1 >= 65) && (char1 <= 90))
		    {
			char1 += 32;
		    }
		    if((char2 >= 65) && (char2 <= 90))
		    {
			char2 += 32;
		    }

		    if(char1 == char2)
		    {
			// if characters are the same letter, return false
			return false;
		    }
		    j++;
		}
	    }
	    i++;
	}
	return true;
    }
}
