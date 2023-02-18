#include <stdio.h>
/**
 * main - this is the main function
 *
 * Return: always 0
 */
int main(void)
{
	printf("Size of a char:%lu byte(s)", sizeof(char));
	printf("size of an int:%lu byte(S)", sizeof(int));
	printf("Size of a long int:%lu byte(s)", sizeof(long int));
	printf("Size of a float:%lu byte(s)", sizeof(float));
	return (0);
}
