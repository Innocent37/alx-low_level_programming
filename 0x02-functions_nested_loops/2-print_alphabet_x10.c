#include "main.h"
/**
 *print_alphabet_10x - functions that prints 10x alphabets
 *
 *Return: always 0
 */


void print_alphabet_10x(void)
{
	int i;
	char j;
	for (i = 1 ; i <=10 ; 1++)
	{
	for (j = 'a' ; j  <= 'z' ; j++)
		_putchar(j);
	_putchar('\n');
	}
}
