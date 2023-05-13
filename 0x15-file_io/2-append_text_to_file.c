#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	size_t len;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	file = fopen(filename, "a");

	if (file == NULL)
		return (-1);

	len = strlen(text_content);

	if (fwrite(text_content, sizeof(char), len, file) != len)
	{
		fclose(file);
		return (-1);
	}

	fclose(file);

	return (1);
}

