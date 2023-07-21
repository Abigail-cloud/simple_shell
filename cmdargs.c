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
			const_builtin = find_builtin
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
 * find_builtinis - finds a builtin command
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

