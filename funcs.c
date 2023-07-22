#include "main.h"


/**
*/

int for_percent(int *p)
{
	_putchar('%');

 	(*p)++;

	return (0);
}
/**
* for_short - prints a short.
* @p: contains the printed char
* @args: the list of the args
* Return: returns zero means success 
*/
int for_short(const char *str, int *p)
{
	if (!str)
	{
		str = "(null)";
	}

	while (*str)
	{
		_putchar(*str);

		(*p)++;

		str++;
	}

	return (0);
}

/**
*/

int for_char(char c, int *p)
{
	_putchar(c);

	(*p)++;

	return (0);
}

/**
*/

int for_integer(int i, int *p)
{
	for_num(i, p);

	return (0);
}


/**
*/


int for_to_binary(unsigned int binary, int *p)
{
	for_binary(binary, p);

	return (0);
}
