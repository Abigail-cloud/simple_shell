#include "shell.h"

/**
 * clear_params - start info_t struct
 * @params: struct address
 *
 */

void clear_params(item_t *params)
{
	params->arg = NULL;
	params->argv = NULL;
	params->path = NULL;
	params->argc =  0;
}

/**
 * set_params - starts the parameter item_t struct
 * @av: argument vector
 * @params: the parameter struct address
 */
void set_params(item_t *params, char **av)
{
	int i = 0;

	params->filename = av[0];
	if (params->arg)
	{
		params->argv = strtow(params->arg, " \t");
		if (!params->argv)
		{

			params->argv = malloc(sizeof(char *) * 2);
			if (params->argv)
			{
				params->argv[0] = my_strdup(params->arg);
				params->argv[1] = NULL;
			}
		}
		for (i = 0; params->argv && params->argv[i]; i++)
			;
		params->argc = i;

swap_alias(params);
swap_vars(params);
	}
}

/**
 * free_params - free the parameter in the item_t struct input
 * @params: the struct parameters
 * @all: free all the input.
 *
 */
void free_params(item_t *params, int all)
{
	my_ffree(params->argv);
	params->argv = NULL;
	params->path = NULL;
	if (all)
	{
		if (!params->cmd_buffer)
			free(params->arg);
		if (params->env)
			free_dlist(&(params->env));
		if (params->history)
			free_dlist(&(params->history));
		if (params->alias)
			free_dlist(&(params->alias));
		my_ffree(params->environ);
		params->environ = NULL;
		osfree((void **)params->cmd_buffer);
		if (params->readdir > 2)
			_putchar(BUFFER_FLUSH);
	}
}
