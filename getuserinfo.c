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
