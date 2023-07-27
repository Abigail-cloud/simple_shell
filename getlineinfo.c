#include "shell.h"

/**
 * sh_hashtag - remove everything after # handdler
 * @buffer: The input buffer
 *
 * Return:void
 */
void sh_hashtag(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '#')
		{
			buffer[i] = '\0';
			break;
		}
	}
}


/**
 * sh_getline - Read The Input By User From Stdin lib
 *
 * Return: Input In Shell
 */
char *sh_getline()
{
	int i, buffersize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffersize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffersize)
		{
			buff = is_realloc(buff, buffersize, buffersize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	sh_hashtag(buff);
	return (buff);
}
