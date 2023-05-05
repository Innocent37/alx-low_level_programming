#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 *
 * @n: a poinrt to a number
 * @index: the index from 0 of bit set
 *
 * Return: 1 on success else -1 encounter error
 *
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
