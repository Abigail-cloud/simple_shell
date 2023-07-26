#include "shell.h"

/**
 * parse_command - the cmd line argument loop
 * @cmd: the arguments and infomation structs
 *
 * Return: 0 on success
 */
char **parse_command(char *cmd)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (cmd == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(cmd, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
