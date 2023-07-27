#include "shell.h"

/**
 * cmd_path - Search In $PATH For Excutable Command in Shell
 * @line: Parsed Input
 *
 * Return: 1
 */
int cmd_path(char **line)
{
	char *path, *value, *sh_path;
	struct stat buf;

	path = my_getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		sh_path = let_build(*line, value);
		if (stat(sh_path, &buf) == 0)
		{
			*line = _strdup(sh_path);
			free(sh_path);
			free(path);
			return (0);
		}
		free(sh_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * let_build - Build Command in Shell
 * @value: Dirctory Conatining Command
 * @token: Excutable Command
 *
 * Return: Parsed  Path
 */
char *let_build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * my_getenv- Gets The Value Of Enviroment Variable By Name
 * In Shell
 * @name: Environment Variable Name Shell
 *
 * Return: Environment Variable Name
 */
char *my_getenv(char *name)
{
	char *value;
	int i, x, j;
	size_t nl, vl;

	nl = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
