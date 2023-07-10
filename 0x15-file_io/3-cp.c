#include "main.h"

/**
 * copy_files - copy content from source file to destination file.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0.
 */
int copy_files(int argc, char **argv)
{
	int src_file, dest_file;
	ssize_t bytes_read = 1024, bytes_written, close_status;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	src_file = open(argv[1], O_RDONLY);
	if (src_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while (bytes_read == 1024)
	{
		bytes_read = read(src_file, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		bytes_written = write(dest_file, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	close_status = close(src_file);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_file);
		exit(100);
	}

	close_status = close(dest_file);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_file);
		exit(100);
	}

	return (0);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	return copy_files(argc, argv);
}

