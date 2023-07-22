#include "shell.h"

/**
 * hsh_loop - the cmd line argument loop
 * @params: the arguments and infomation structs
 * @av: the argument vector to main function.
 *
 * Return: 0 on success
 */
int hsh_loop(item_t *params, char **av)
{
	ssize_t y = 0;
	int const_builtin = 0;

	while (y != -1 && const_builtin != -2)
	{
		clear_params(params);
		if (terminal(params))
			_puts("$ ");
		_fputschar(BUFFER_FLUSH);
		y = get_res(params);
		if (y != -1)
		{
			set_info(params, av);
			const_builtin = find_builtins
				(params);
			if (find_builtin == -1)
				find_command(params);
		}
		else if (terminal(params))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(params);
	free_info(params, 1);
	if (terminal(params) && params->status)
		exit(params->status);
	if (const_builtin == -2)
	{
		if (params->err_num == -1)
			exit(params->status);
		exit(params->err_num);
	}
	return (const_builtin);
}

/**
 * find_builtins - finds a builtin command
 * @params: the parameter information struct
 *
 * Return: -1 if not builtin
 *
 */
int find_builtins(item_t *params)
{
	int i, built_const = -1;
	builtin_info builtin_infox[] = {
		{"exit", _onexit},
		{"env", _onenv},
		{"help", _onhelp},
		{"history", _onhistory},
		/*other buitin neede to be added*/
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtin_infox[i].type; i++)
		if (_strcmp(params->argv[0], builtin_infox[i].type) == 0)
		{
			params->line_count++;
			built_const = builtin_infox[i].func(params);
			break;
			}
	return (built_const);
}

/**
 * find_prompt - finds a prompt cmd in PATH
 * @params: the parameter information struct
 *
 * Return: void
 */
void find_prompt(item_t *params)
{
	char *path = NULL;
	int i, j;

	params->path = params->argv[0];
	if (params->count_flag == 1)
	{
		params->line_count++;
		params->count_flag = 0;
	}
	for (i = 0, j = 0; params->arg[i]; i++)
		if (!is_delim(params->arg[i], " \t\n"))
			j++;
	if (!j)
		return;

	path = get_path((param, get_env(params,  "PATH="), params->argv[0]);
			if (path)
			{
			params->path = path;
			fork_prompt(params);
			}
			else
			{
			if ((terminal(params) || get_env(params, "PATH=")
						|| params->argv[0][0] == '/') && cmd_exe(params, params->argv[0]))
			fork_prompt(params);
			else if (*(params->arg) != '\n')
			{
			params->status = 127;
			log_error(params, "not found\n");
			}
			}
} 

/**
 * fork_prompt - forks an executable prompt to run command
 * @params: the parameter info struct
 *
 * Return: void
 */
void fork_prompt(item_t *params)
{
	pid_t fork_pid;

	fork_pid = fork();
	if (fork_pid == -1)
	{
			perror("Error:");
			return;
	}
	if (fork_pid == 0)
	{
		if (execve(params->path, params->argv, get_env(params)) == -1)
		{
			free_info(params, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(params->status));
		if (WIFEXITED(params->status))
		{
			params->status = WEXITSTATUS(params->status);
			if (params->status == 126)
				log_error(info, "Permission denied\n");
		}
	}
}
