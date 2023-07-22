#include "shell.h"

/**
 * cmd_exe - checks if the file is an executable.
 * @params: the parameter info struct
 * @path: path to the file
 *
 * Return: 1
 */
int cmd_exe(item_t *params, char *path)
{
		struct stat st;

		(void)params;
		if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
{
	return (1);
}
return (0);
}

/**
 * double_chars - doubles characters
 * @start: starts index loop
 * @stop: stops index loop
 * @pathstr: the PATH string
 *
 * Return: the pointing pointer
 */
char *double_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[j++] = pathstr[i];
	buf[j] = 0;
	return (buf);
}

/**
 * cmd_path - checks if cmd in the PATH string
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * @params: the parameter infomation struct
 *
 * Return: full path
 */
char *cmd_path(item_t *params, char *pathstr, char *cmd)
{
	int i = 0, current_index = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (cmd_exe(params, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = double_chars(pathstr, current_index, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (cmd_exe(params, path))
				return (path);
			if (!pathstr[i])
				break;
			current_index = i;
		}
		i++;
	}
	return
}
