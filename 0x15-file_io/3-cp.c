#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int open_file(const char *filename, int flags, int mode);
void close_file(int fd);
void print_error(const char *message, const char *arg);
void exit_with_error(int code, const char *message, const char *arg);

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, r, w;
	char buffer[BUF_SIZE];

	if (argc != 3)
		exit_with_error(97, "Usage: cp file_from file_to\n", NULL);

	file_from = open_file(argv[1], O_RDONLY, 0);
	file_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	while ((r = read(file_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w != r)
			exit_with_error(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (r == -1)
		exit_with_error(98, "Error: Can't read from file %s\n", argv[1]);

	close_file(file_from);
	close_file(file_to);

	return (0);
}

/**
 * open_file - Opens a file.
 * @filename: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The file mode to set if creating the file.
 *
 * Return: The file descriptor of the opened file, or -1 on failure.
 */
int open_file(const char *filename, int flags, int mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
		exit_with_error(98, "Error: Can't read from file %s\n", filename);
	return (fd);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
		print_error("Error: Can't close fd %d\n", NULL);
}

/**
 * print_error - Prints an error message to stderr.
 * @message: The error message format string.
 * @arg: The argument for the error message.
 */
void print_error(const char *message, const char *arg)
{
	dprintf(2, message, arg);
}

/**
 * exit_with_error - Exits the program with an error code
 * @code: The exit code.
 * @message: The error message format string.
 * @arg: The argument for the error message.
 */
void exit_with_error(int code, const char *message, const char *arg)
{
	print_error(message, arg);
	exit(code);
}

