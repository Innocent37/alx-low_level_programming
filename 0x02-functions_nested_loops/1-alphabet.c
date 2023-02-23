#include "main.h"
/**
 * print_alphabet - functions that print letters in lowercase
 *
 * print_alphabet - functions that print letter in lowecase
 * Return: always 0;
 */

void print_alphabet(void)
{
	char letter;


		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
			_puchar('\n');
