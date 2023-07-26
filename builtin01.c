#include "shell.h"

/**
 * my_cd - change the shell directories in LINUX
 * @rt: the last command status
 * @cmd: Parsed Command in the shell
 *
 * Return: 0
 */

int my_cd(char **cmd, __attribute__((unused))int rt)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * exit_bul - Esxiting the shell status
 * @input: User Input
 * @argv:Program Name pointer
 * @c: counter
 * @cmd: Parsed Command to the shell
 *
 * Return: void
 */
void  exit_bul(char **cmd, char *input, char **argv, int c)
{
	int stat, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			sh_prerror(argv, c, cmd);
			break;
		}
		else
		{
			stat = _ascitoi(cmd[1]);
			free(input);
			free(cmd);
			exit(stat);
		}
	}
}

/**
 * sh_env - it display the shell env variable
 * @rt: status of the last used command
 * @cmd:Parsed shell command
 *
 * Return: 0
 */
int sh_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int rt)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - show the help command to see
 * meaning of other functions
 * @cmd:Parsed shell command
 * @rt: status of the last used command
 *
 * Return: 0
 */
int display_help(char **cmd, __attribute__((unused))int rt)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * sh_echo - let the echo function work
 * @rt: the status of the last command
 * @cmd: the parsed shell command
 *
 * Return: 0
 */

int sh_echo(char **cmd, int rt)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		log_number_in(rt);
		LOG("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		log_number(pid);
		LOG("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = my_getenv("PATH");
		LOG(path);
		LOG("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
