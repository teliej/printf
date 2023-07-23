#include "main.h"


/**
*/

int for_percent(int *p, char *buff, int *buff_index)
{
	_putchar('%', buff, buff_index);

 	(*p)++;

	return (0);
}
/**
* for_short - prints a short.
* @p: contains the printed char
* @args: the list of the args
* Return: returns zero means success 
*/
int for_short(const char *str, int *p, char *buff, int *buff_index)
{
	if (!str)
	{
		str = "(null)";
	}

	while (*str)
	{
		_putchar(*str, buff, buff_index);

		(*p)++;

		str++;
	}

	return (0);
}

/**
*/

int for_char(char c, int *p, char *buff, int *buff_index)
{
	_putchar(c, buff, buff_index);

	(*p)++;

	return (0);
}

/**
*/

int for_integer(int i, int *p, char *buff, int *buff_index)
{
	for_num(i, p, buff, buff_index);

	return (0);
}


/**
*/


int for_to_binary(unsigned int binary, int *p, char *buff, int *buff_index)
{
	for_binary(binary, p, buff, buff_index);

	return (0);
}


int for_unsign(unsigned int i, int *p, char *buff, int *buff_index)
{
	if (i / 10 != 0)
		for_unsign(i / 10, p, buff, buff_index);
	_putchar('0' + (i % 10), buff, buff_index);
	(*p)++;
	return (0);
}


int for_octal(unsigned int j, int *p, char *buff, int *buff_index)
{
	if (j / 8 != 0)
		for_octal(j / 8, p, buff, buff_index);
	_putchar('0' + (j % 8), buff, buff_index);
	(*p)++;
	return (0);
}




void for_lower_hex(unsigned int k, int *p, char *buff, int *buff_index)
{
	char *str;

	str = "0123456789abcdef";

	if (k / 16 != 0)
		for_lower_hex(k / 16, p, buff, buff_index);

	_putchar(str[k % 16], buff, buff_index);

	(*p)++;
}

void for_upper_hex(unsigned int k, int *p, char *buff, int *buff_index)
{
	char *str;

	str = "0123456789ABCDEF";

	if (k / 16 != 0)
		for_upper_hex(k / 16, p, buff, buff_index);

	_putchar(str[k % 16], buff, buff_index);

	(*p)++;
}
