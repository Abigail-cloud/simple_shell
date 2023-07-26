#include "shell.h"

/**
 * log_number - print the executable output.
 * @n: Integer unsigned
 *
 * Return: void output
 */
void log_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		log_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * log_number_in - Print number into the putchar function
 * @n: integer input
 *
 * Return: void.
 */
void log_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		log_number(x / 10);

	_putchar(x % 10 + '0');
}

