#include "shell.h"

/**
 * _strcpy - file copy the source to a destined char
 * @src:Source file
 * @dest:Destination inshell
 *
 * Return: copied char
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - string duplicated or doubled
 * @str: The string
 * Return: The duplicated string
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}

/**
 * _strcat - Funtion that Concatenate Two Strings
 * @src:Second String source
 * @dest:First String destination
 *
 * Return: The addition of dest and src
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strchr - Locating the  Characters in a String
 * @c:Char To Search in a string
 * @s: The String
 *
 * Return: The pointer to char*
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return (s);
}


/**
 * _strncmp - Compare Amount(n) Of Characters Of Two Strings.
 * @s1: First String
 * @s2: Second String.
 * @n: Amount Of Characters compared
 *
 * Return: 1
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
