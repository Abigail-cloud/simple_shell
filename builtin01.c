#include "shell.h"

/**
 * _shexit - exits the shell environment
 * @params: the parameter struct
 *
 * Return: the information in params
 */
int _shexit(item_t *params)
{
	int exitshell;

	if (params->argv[1])
	{
		exitshell = _errstr(params->argv[1]);
		if (exitshell == -1)
		{
			params->status = 2;
			log_error(params, "Wrong number input: ");
			_fputs(params->argv[1]);
			_fputchar('\n');
			return (1);
		}
		params->err_num = _errstr(params->argv[1]);
		return (-2);
	}
	params->err_num = -1;
	return (-2);
}
