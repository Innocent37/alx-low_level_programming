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
	/* Variable Declarations */
	FILE *file;
	int fd, w, len = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Calculate length of text_content */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* Open the file using open() */
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Associate a FILE* stream with the file descriptor */
	file = fdopen(fd, "w");
	if (file == NULL)
	{
		close(fd);
		return (-1);
	}

	/* Write text_content to the file */
	if (text_content != NULL)
	{
		w = fwrite(text_content, sizeof(char), len, file);
		if (w != len)
		{
			fclose(file);
			return (-1);
		}
	}

	/* Close the file and return success */
	fclose(file);
	return (1);
}

