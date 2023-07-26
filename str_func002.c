#include "shell.h"

/**
 * _strcmp - The comapaism between two string
 * @s1:String 1
 * @s2:String 2 comapared
 *
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int cm = 0, i, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cm = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cm);
}

/**
 * _isalpha - Is it an alphabeltic value
 * @c: Character value
 *
 * Return: 1
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _istoi - is it converted from integer to character
 * @n: Integer to be converted
 *
 * Return: charactr
 */
char *_istoi(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * array_rev - Reversing the array
 * @len:Length Of Array in memory
 * @arr:Array To Reversed
 *
 * Return: reversed array
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - check the length of a given integer
 * @num: Given Integer
 *
 * Return: Length.
 */

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
