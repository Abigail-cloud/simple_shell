#include "shell.h"

/**
 * is_realloc - The Reallocation of a Memory Block while using
 * Malloc And Free
 * @old_size: Previous Size Of The Pointer shell
 * @new_size: New Size Of The Pointer shell
 * @ptr: Pointer
 *
 * Return: voided pointer
 */

void *is_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *res;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new_size);
	if (res == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		put_array(res, '\0', new_size);
		free(ptr);
	}
	else
	{
		_mempy(res, ptr, old_size);
		free(ptr);
	}
	return (res);

}

/**
 * _mempy - copy a byte from source file to the destination shell
 * @src: Source Pointer shell
 * @n: Size of the copied file
 * @dest: Destination Pointer Shell
 *
 * Return: void
 */
char *_mempy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * free_all - Free Array Of Char Pointer And Char Pointer shell
 * @line:Char Pointer shell
 * @input: The array input poiter
 *
 * Return: Void
 */
void free_all(char **input, char *line)
{
	free(input);
	free(line);
	input = NULL;
	line = NULL;
}

/**
 * put_array - Fill An Array By Constant Byte SHELL
 * @element: The integer
 * @a: The void pointer
 * @len: The length integer
 *
 * Return: Void Pointer
 */
void *put_array(void *a, int element, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = element;
		p++;
		i++;
	}
	return (a);
}


/**
 * is_calloc - Allocates Memory For An Array, Using Malloc FUNCTION.
 * @size: Size
 *
 * Return: Void Pointer
 */
void *is_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
