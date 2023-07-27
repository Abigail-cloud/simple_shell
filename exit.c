#include "shell.h"

/**
 * read_my_file- Read Command From File in Shell
 * @argv:Program Name
 * @filename:Filename read in shell
 *
 * Return: -1 or  0
 */
void read_my_file(char *filename, char **argv)
{
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		sh_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * sh_file - PARSE Check Command Fork Wait Excute
 * @counter:Error Counter
 * @fd: File Descriptor
 * @argv:Program Name
 * @line: Line From A File
 *
 * Return : void
 */
void sh_file(char *line, int counter, FILE *fd, char **argv)
{
		char **cmd;
		int st = 0;

		cmd = parse_command(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_file(cmd, line, fd);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_sh_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_my_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}

/**
 * exit_file - Exit Shell Case Of File
 * @cmd: Parsed Command
 * @line: Line From A File
 * @fd:File Descriptor
 *
 * Return : Exited Line
 */
void exit_file(char **cmd, char *line, FILE *fd)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
		status = _ascitoi(cmd[1]);
		free(line);
		free(cmd);
		fclose(fd);
		exit(status);


}
