#include "shell.h"

/**
 * _putchar - writes the character c to standard out
 * @c: The character
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copy a string
 * @src:character
 * @n:integer
 * @dest:character destination
 *
 * Return: character
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - The string length
 * @s:character string
 *
 * Return: integer returned
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _puts - The string is printed out.
 * @str: character string to be printed
 *
 * Return: void
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
