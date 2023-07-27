#include "shell.h"

/**
 * main - Simple Shell (Hsh) logic
 * @argv:Argument Value
 * @argc: Argument Count
 *
 * Return: values by status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int counter = 0, status = 1, st = 0;
	char *input, **cmd;

	if (argv[1] != NULL)
		read_my_file(argv[1], argv);
	signal(SIGINT, signal_handel);
	while (status)
	{
		counter++;
if (isatty(STDIN_FILENO))
	prompt();
input = sh_getline();
if (input[0] == '\0')
{
	continue;
}
is_history(input);
cmd = parse_command(input);
if (_strcmp(cmd[0], "exit") == 0)
{
	exit_bul(cmd, input, argv, counter);
}
else if (check_builtin(cmd) == 0)
{
	st = handle_sh_builtin(cmd, st);
	free_all(cmd, input);
	continue;
}
else
{
	st = check_my_cmd(cmd, input, counter, argv);

}
free_all(cmd, input);
}
return (status);
	}

/**
 * check_builtin - check builtin shell
 * @cmd:command to check
 *
 * Return: 0
 */
int check_builtin(char **cmd)
{
	int i = 0;

	builtin_info fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->type)
	{
		if (_strcmp(cmd[0], (fun + i)->type) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * create_env - get Array of Enviroment Variable
 * @envin: Array of Enviroment Variable shell
 *
 * Return: void
 */
void create_env(char **envin)
{
	int i;

	for (i = 0; environ[i]; i++)
		envin[i] = _strdup(environ[i]);
	envin[i] = NULL;
}
