#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/* Function Prototypes */
int open_file(const char *filename, int flags, int mode);
void close_file_descriptor(int fd);
char *allocate_buffer(char *file);

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: An array of strings containing the arguments
 *
 * Return: 0 on success, or the corresponding exit code on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	file_from = open_file(argv[1], O_RDONLY, 0);
	file_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	do {
		r = read(file_from, buffer, BUF_SIZE);
		if (file_from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(file_to, buffer, r);
		if (file_to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

	} while (r > 0);

	close_file_descriptor(file_from);
	close_file_descriptor(file_to);
	free(buffer);

	return (0);
}

/**
 * open_file - Opens a file
 * @filename: The name of the file to open
 * @flags: The flags to use when opening the file
 * @mode: The file mode to set if creating the file
 *
 * Return: The file descriptor of the opened file, or -1 on failure
 */
int open_file(const char *filename, int flags, int mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * close_file_descriptor - Closes a file descriptor
 * @fd: The file descriptor to close
 */
void close_file_descriptor(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * allocate_buffer - Allocates memory for a buffer
 * @file: The name of the file buffer is storing chars for
 *
 * Return: A pointer to the newly-allocated buffer
 */
char *allocate_buffer(char *file)
{
	char *buffer = malloc(sizeof(char) * BUF_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

