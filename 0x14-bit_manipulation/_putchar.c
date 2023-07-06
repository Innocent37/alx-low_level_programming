#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success, the number of characters written.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char b)
{
	return (write(1, &b, 1));
}

