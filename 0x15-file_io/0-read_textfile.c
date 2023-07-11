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
	int files;
	char *name;
	ssize_t reading;

	if (!filename)
		return (0);
	files = open(filename, O_RDONLY);
	if (name == NULL)
		return (0);
	name = malloc(sizeof(char) * letters + 1);
	if (files == -1)
	{
		free(name);
		return (0);
	}
	reading = read(files, name, sizeof(char) * letters);
	if (reading == -1)
	{
		free(name);
		close(files);
		return (0);
	}
	reading = write(STDOUT_FILENO, name, reading);
	if (reading == -1)
	{
	free(name);
	close(files);
	return (0);
}
	free(name);
	close(files);
	return (reading);
	}
