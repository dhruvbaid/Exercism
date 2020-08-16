#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* atbash_encode(const char* input)
{
    // allocate space for encoded message
    char* encoded = (char*)malloc(strlen(input) * sizeof(char));
    
    // encode input and store it in encoded
    unsigned int spaces = 0, i = 0;
    for(i = 0; i < strlen(input); i++)
    {
	char curr = input[i];

	if((curr >= 65) && (curr <= 90))
	{
	    // capital letter - convert to small before ciphering
	    encoded[i - spaces] = 219 - (curr + 32);
	}
	else if((curr >= 97) && (curr <= 122))
	{
	    // small letter - cipher immediately
	    encoded[i - spaces] = 219 - curr;
	}
	else if((curr >= 48) && (curr <= 57))
	{
	    // digit - leave it as it is
	    char tmp = curr;
	    encoded[i - spaces] = tmp;
	}
	else
	{
	    // punctuation - ignore
	    spaces++;
	}
    }
    
    // terminate encoded correctly to account for punctuation in input
    if(spaces)
    {
	encoded[i - spaces] = '\0';
    }
    
    // compute number of spaces needed for final result
    unsigned int num_spaces = (strlen(encoded) - 1) / 5;
    unsigned int len_final = num_spaces + strlen(encoded);

    // allocate memory for final result
    char* res = (char*)malloc(len_final * sizeof(char));
    
    // add spaces every 5th character of encode, store in res
    unsigned int count = 0;
    spaces = 0;
    for(unsigned int i = 0; i < len_final; i++)
    {
	if(count != 5)
	{
	    res[i] = encoded[i - spaces];
	    count++;
	}
	else
	{
	    res[i] = 32;
	    count = 0;
	    spaces++;
	}
    }

    return res;
}

char* atbash_decode(const char* input)
{
    unsigned int len = strlen(input);
    char* res = (char*)malloc(len * sizeof(char));
    unsigned int spaces = 0, i = 0;
    for(i = 0; i < len; i++)
    {
	char curr = input[i];
	if((curr >= 97) && (curr <= 122))
	{
	    // small letter - decode
	    res[i - spaces] = 219 - curr;
	}
	else if((curr >= 48) && (curr <= 57))
	{
	    // digit - leave it as it is
	    char tmp = curr;
	    res[i - spaces] = tmp;
	}
	else
	{
	    spaces++;
	}
    }
    if(spaces)
    {
	res[i - spaces] = '\0';
    }

    return res;
}
