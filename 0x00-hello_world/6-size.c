#include <stdio.h>
/**
 * main - this is the main function
 *
 * Return: always 0
 */
int main(void)
{
	printf("Size of a char:%lu byte(s)\n", sizeof(char));
	printf("size of an int:%lu byte(S)\n", sizeof(int));
	printf("Size of a long int:%lu byte(s)\n", sizeof(long int));
	printf("Size of a long long int:%lu byte(s)\n", sizeof(long long int));
	printf("Size of a float:%lu byte(s)\n", sizeof(float));
	return (0);
}