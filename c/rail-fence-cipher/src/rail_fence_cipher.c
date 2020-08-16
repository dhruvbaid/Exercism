#include "rail_fence_cipher.h"
#include <string.h>

char *encode(char *text, size_t rails)
{
    // allocate memory for the encoded message
    unsigned int len = strlen(text);
    char* encoded = (char*)malloc(len * sizeof(char));

    if((rails == 1) || (rails > len))
    {
	for(unsigned int i = 0; i < strlen(text); i++)
	{
	    char curr = text[i];
	    encoded[i] = curr;
	}
    }
    else
    {
	// rows contains the row which each character will be placed in
	unsigned int* rows = (unsigned int*)malloc(len * sizeof(unsigned int));
	unsigned int repeat_len = (2 * rails) - 2;
	for(unsigned int i = 0; i < len; i++)
	{
	    unsigned int tmp = (i % repeat_len) + 1;
	    unsigned int row;
	    row = (tmp > rails) ? ((2 * rails) - tmp) : tmp;
	    rows[i] = row;
	}

	// read from the rows array to identify the character order for encoded
	unsigned int count = 0;

	for(unsigned int i = 1; i < rails + 1; i++)
	{
	    // i represents the row which we are reading from
	    for(unsigned int j = 0; j < len; j++)
	    {
		// j loops through the rows array to find characters in row i
		if(rows[j] == i)
		{
		    char curr = text[j];
		    encoded[count] = curr;
		    count++;
		}
	    }
	}
    }
    
    // terminate the encoded message at the correct spot and return it
    encoded[len] = '\0';
    return encoded;
}

char *decode(char *ciphertext, size_t rails)
{
    // allocate memory for the decoded message
    unsigned int len = strlen(ciphertext);
    char* decoded = (char*)malloc(len * sizeof(char));

    if(rails == 1)
    {
	for(unsigned int i = 0; i < len; i++)
	{
	    char curr = ciphertext[i];
	    decoded[i] = curr;
	}
    }
    else
    {
	// rows contains the row which each character will be placed in
	unsigned int* rows = (unsigned int*)malloc(len * sizeof(unsigned int));
	unsigned int repeat_len = (2 * rails) - 2;
	for(unsigned int i = 0; i < len; i++)
	{
	    unsigned int tmp = (i % repeat_len) + 1;
	    unsigned int row;
	    row = (tmp > rails) ? ((2 * rails) - tmp) : tmp;
	    rows[i] = row;
	}
	
	// pos[i] represents the position of ciphertext[i] in the actual text
	unsigned int* pos = (unsigned int*)malloc(len * sizeof(unsigned int));
	unsigned int count = 0;
	for(unsigned int i = 1; i < rails + 1; i++)
	{
	    for(unsigned int j = 0; j < len; j++)
	    {
		if(rows[j] == i)
		{
		    pos[count] = j;
		    count++;
		}
	    }
	}

	// find the character at index count in the actual message
	count = 0;
	while(count < len)
	{
	    for(unsigned int i = 0; i < len; i++)
	    {
		if(pos[i] == count)
		{
		    char tmp = ciphertext[i];
		    decoded[count] = tmp;
		    count++;
		}
	    }
	}
    }
    
    // terminate the decoded message at the correct spot and return it
    decoded[len] = '\0';
    return decoded;
}
