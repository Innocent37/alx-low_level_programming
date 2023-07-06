#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to the string representing the binary number
 *
 * Return: The converted unsigned int, or 0 on error
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int results = 0;

	if (b == NULL)
		return (0);

	for (; *b; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);

		results = (results << 1) + (*b - '0');
	}

	return (results);
}

int main(void)
{
	const char *binary1 = "1";
	const char *binary2 = "101";
	const char *binary3 = "0";
	const char *binary4 = "1100010";
	const char *binary5 = "110010010";

	printf("%u\n", binary_to_uint(binary1));
	printf("%u\n", binary_to_uint(binary2));
	printf("%u\n", binary_to_uint(binary3));
	printf("%u\n", binary_to_uint(binary4));
	printf("%u\n", binary_to_uint(binary5));

	return (0);
}

