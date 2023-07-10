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
	int file;
	char *text;
	ssize_t nletters, reading;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	text = malloc(sizeof(char) * (letters + 1));
	if (text == NULL)
	{
		close(file);
		return (0);
	}

	nletters = read(file, text, sizeof(char) * letters);
	if (nletters == -1)
	{
		free(text);
		close(file);
		return (0);
	}

	text[nletters] = '\0';
	printf("%s", text);

	free(text);
	close(file);
	return (nletters);
}

