#include "shell.h"

/**
 * check_delim - Checking of a character matching
 * char*
 * @c: The character
 * @str: String
 *
 * Return: 1
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _ascitoi - convert ascii to a int
 * @s:string
 * Return: integer
 */
int _ascitoi(char *s)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _strtok - A string token
 * @item: Delimiter
 * @str: String
 *
 * Return: Next token
 */
char *_strtok(char *str, const char *item)
{
	static char *token;
	static char *next_token;
	unsigned int i;

	if (str != NULL)
		next_token = str;
	token = next_token;
	if (token == NULL)
		return (NULL);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (check_delim(token[i], item) == 0)
			break;
	}
	if (next_token[i] == '\0' || next_token[i] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token = next_token + i;
	next_token = token;
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_delim(next_token[i], item) == 1)
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token);
}
