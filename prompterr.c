#include "shell.h"

/**
 * log_error - log the error based on the last command
 * displayed
 * @line m: user input
 * @c: shell loop counter
 * @argv:Program Name Parameter
 *
 * Return: void
 */
void log_error(char *line, int c, char **argv)
{
	char *rt;

	LOG(argv[0]);
	LOG(": ");
	rt = _istoi(c);
	LOG(rt);
	free(rt);
	LOG(": ");
	LOG(line);
	LOG(": not found\n");
}

/**
 * prompt - Display Shell Prompt output
 *
 * Return: void
 */
void prompt(void)
{
	LOG("$ ");
}

/**
 * sh_prerror - Log the error custyomized function
 * @c:Error Counter input
 * @cmd:Command value
 * @argv:Program Name Parameter
 *
 * Return: void
 */
void sh_prerror(char **argv, int c, char **cmd)
{
	char *rt = _istoi(c);

		LOG(argv[0]);
	LOG(": ");
	LOG(rt);
	LOG(": ");
	LOG(cmd[0]);
	LOG(": Illegal number: ");
	LOG(cmd[1]);
	LOG("\n");
	free(rt);
}
