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
