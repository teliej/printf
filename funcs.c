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


int for_unsign(unsigned int i, int *p)
{
	if (i / 10 != 0)
		for_unsign(i / 10, p);
	_putchar('0' + (i % 10));
	(*p)++;
	return (0);
}


int for_octal(unsigned int j, int *p)
{
	if (j / 8 != 0)
		for_octal(j / 8, p);
	_putchar('0' + (j % 8));
	(*p)++;
	return (0);
}




void for_lower_hex(unsigned int k, int *p)
{
	char *str;

	str = "0123456789abcdef";

	if (k / 16 != 0)
		for_lower_hex(k / 16, p);

	_putchar(str[k % 16]);

	(*p)++;
}

void for_upper_hex(unsigned int k, int *p)
{
	char *str;

	str = "0123456789ABCDEF";

	if (k / 16 != 0)
		for_upper_hex(k / 16, p);

	_putchar(str[k % 16]);

	(*p)++;
}
