#include "main.h"

/**
 * get_bit - return the value of a bit a given index
 * @n: the number to get the bit fro
 * @index: the index of thr bit to gt starting from number  0
 *
 * Return: the value of a bit at the index or -1 if theres an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n >> index) & 1);
}
