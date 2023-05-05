#include "main.h"

/**
 * flip_bits - Returns the number of bits required to flip one to another
 *
 * @n: the first nuber
 * @m: the seconf number
 *
 * Return: the number of bits required to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int change = n ^ m;
	unsigned int sum = 0;

	while (change > 0)
	{
		if ((change & 1) == 1)
		sum++;

				change >>= 1;
	}
		return (change);
}
