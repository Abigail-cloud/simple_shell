#include "shell.h"

/**
 * _shhistory - Display History Of User Input Simple Shell
 * @c: parsed command shell
 * @s: status of last excutable command
 *
 * Return: 0
 */
int _shhistory(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *rt;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		rt = _istoi(counter);
		LOG(rt);
		free(rt);
		LOG(" ");
		LOG(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * print_echo -  parsed the regular shell echo
 * @cmd: Parsed Command Shell
 *
 * Return: 0
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}
