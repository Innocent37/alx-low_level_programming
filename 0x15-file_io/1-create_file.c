#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#include <string.h>


/**
 * create_file - creates a file with a file naeme
 * @filename: points to the file
 * @text_content: a points to a file tha will write
 *
 * Return: 1 is fails else -1
 */

int create_file(const char *filename, char *text_content)
{
	int len = 0;
	FILE *file = NULL;
	int w = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{

		while (text_content[len] != '\0')
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
	return (-1);
}
