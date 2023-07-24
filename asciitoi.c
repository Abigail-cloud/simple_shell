#include "shell.h"

/**
 * terminal - returns true if terminal is in interactive mode
 * @params: struct address
 *
 * Return: 1
 */ 
int terminal (item_t *params)
{
	return (isatty(STDIN_FILENO) && params->readdir <= 2);
}

/**
 * is_delim - checks if the char is a delimeter
 * @delim: the delimeter string
 * @c: the char
 *
 * Return: 1
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * is_alpha - see if char is alphabet
 * @c: The character
 *
 * Return: 1
 */
int is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * astoi - converts ACII to an integer
 * @s: the string
 *
 * Return: string
 */
int astoi(char *s)
{
	int i, sign = 1, flag = 0, out;
	unsigned int response = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			response *= 10;
			response += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		out = -response;
	else
		out = response;

	return (out);
}
