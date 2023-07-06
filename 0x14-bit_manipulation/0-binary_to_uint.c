#include <stdlib.h>
#include "main.h"
/**
 * binary_to_uint - converts a binary nuber to an unsigned int
 * @b: pointer to a string of 0 and 1 char
 *
 * Return: converted valu or 0 if theres one or more chaars in the string
 * b that is not 0 or 1 if b is null
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int total = 0;
	int i;
		if (b == NULL)
		return (0);
	for (i = 0; b[i] != '\0'; ++i)
		{
		if (b[i] == '0')
			total = (total << 1);
			else if (b[i] == '1')
			total = (total << 1 | 1);
				else
				return (0);
		}

	return (total);
}
