#include "shell.h"

/**
 * is_history - The history searched by user
 * @input: User Input Shell
 *
 * Return: 0
 */
int is_history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}


/**
 * free_env - Free Enviroment Variable Array SHell
 * @env:  Environment variables in Shell.
 *
 * Return: Void
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
