#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	FILE *file;
	int w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	file = fopen(filename, "w");
	if (file == NULL)
		return (-1);

	if (text_content != NULL)
	{
		w = fwrite(text_content, sizeof(char), len, file);
		if (w != len)
		{
			fclose(file);
			return (-1);
		}
	}

	fclose(file);

	return (1);
}

