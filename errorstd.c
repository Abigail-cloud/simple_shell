#include "shell.c"

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
