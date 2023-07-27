#include "shell.h"

/**
 * handle_sh_builtin - Handle Builtin Command
 * @cmd: Parsed Command shell
 * @rt: status of last executed command
 *
 * Return: 0
 */
int handle_sh_builtin(char **cmd, int rt)
{
	int i = 0;

	builtin_info bul[] = {
		{"cd", my_cd},
		{"env", sh_env},
		{"help", display_help},
		{"echo", sh_echo},
		{"history", _shhistory},
		{NULL, NULL}
	};

	while ((bul + i)->type)
	{
		if (_strcmp(cmd[0], (bul + i)->type) == 0)
		{
			return ((bul + i)->func(cmd, rt));
		}
		i++;
	}
	return (-1);
}

/**
 * check_my_cmd - Excute Simple Shell Command (Fork,Wait,Excute) in
 * shell
 * @tokens:Parsed Command
 * @line: User Input
 * @count:Shell count
 * @argv: Program Name
 *
 * Return: 1
 */
int check_my_cmd(char **tokens, char *line, int count, char **argv)
{
	int status;
	pid_t pid;

	if (*tokens == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*tokens, "./", 2) != 0 && _strncmp(*tokens, "/", 1) != 0)
		{
			cmd_path(tokens);
		}

		if (execve(*tokens, tokens, environ) == -1)
		{
			log_error(tokens[0], count, argv);
			free(line);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

/**
 * signal_handel - Handle ^C in shell
 * @sig:Captured Signale
 *
 * Return: Void
 */
void signal_handel(int sig)
{
	if (sig == SIGINT)
	{
		LOG("\n$ ");
	}
}
