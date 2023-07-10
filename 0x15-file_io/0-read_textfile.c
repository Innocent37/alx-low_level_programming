#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX stdout
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         Returns 0 if filename is NULL or if an error occurs.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *files;
	char *name;
	ssize_t reading;

	if (filename == NULL)
		return (0);

	files = fopen(filename, "r");
	if (files == NULL)
		return (0);

	name = malloc(sizeof(char) * (letters + 1));
	if (name == NULL)
	{
		fclose(files);
		return (0);
	}

	reading = fread(name, sizeof(char), letters, files);
	if (reading <= 0)
	{
		free(name);
		fclose(files);
		return (0);
	}

	name[reading] = '\0';
	printf("%s", name);

	free(name);
	fclose(files);
	return (reading);
}

