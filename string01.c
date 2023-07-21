#include "shell.h"

/**
 * _puts - prints a string inputs
 * @str: the string
 *
 * Return: NONE
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character output
 *
 * Return: On success
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}
