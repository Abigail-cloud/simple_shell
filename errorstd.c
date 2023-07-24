#include "shell.h"

/**
 * _fputchar - writes the character c to stderror
 * @c: The character output
 *
 * Return: On success.
 *
 */
int _fputchar(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _efputs - output sting input error
 * @str: the string output.
 *
 * Return: None
 */
void _efputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_fputchar(str[i]);
		i++;
	}
}

/**
 * my_buffd - function that is used for buffered
 * output to a file descriptor.
 * @fd: The filedescriptor
 * @c: The character output
 *
 * Return: 1
 */
int my_buffd(char c, int fd)
{
	static int i;
	static char buffer[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * my_puts - variation of the standard puts function,
 * prints it to the specified file descriptor
 * @fd: the file descriptor
 * @str: the string printed.
 *
 * Return: number of characters printed
 */
int my_puts(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += my_buffd(*str++, fd);
	}
	return (i);
}
