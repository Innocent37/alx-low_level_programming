#include "main.h"

/**
 * get_endianness - checks the endianess of MACHINE
 *
 * Return: 0 if true then 1 if flase
 */
int get_endianness(void)
{
	unsigned int c = 1;
	char *x = (char *)&x;

	return (*x ? 1 : 0);
}
