#include "main.h"

/**
 * set_bit - sets the valu of a bit to 1 at a given index
 * @n: pointer to a number
 * @index: index of the bit to set (strting from 0)
 *
 * Return: 1 if true the -1 if false
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /* false */

	*n |= (1UL << index);

	return (1); /* true */
}

