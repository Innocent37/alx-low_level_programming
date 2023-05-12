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

int create_file(const char *filename, char *text_content);
{
	if (filename == NULL)
		return (-1);

	int file_d;
		ssize_t result;

	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_d == -1)
		return (-1);

	if (text_content != NULL)
	{
		result = write(file_d, text_content, strlen(text_content));
		if (result == -1)
		{
			close(file_d);
			return (-1);
		}
	}

	close(file_d);
		return (1);
}
