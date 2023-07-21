#include "shell.h"

int terminal (item_t *params)
{
	return (isatty(STDIN_FILENO) && params->readdir <= 2);
}
