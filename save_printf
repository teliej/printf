#include <stdio.h>
#include <stdarg.h>
#include "main.h"



int for_binary(unsigned int binary, int *p)
{
	if (binary / 2 != 0)
		for_binary(binary / 2, p);

	_putchar('0' + (binary % 2));

	(*p)++;

	return (0);
}

int for_num(int i, int *p)
{
	unsigned int j;

	if (i < 0)
	{
		_putchar('-');
		(*p)++;
		j = -i;
	}
	else
		j = i;

	if (j / 10 != 0)
		for_num(j / 10, p);

	_putchar(j % 10 + '0');
	(*p)++;
	return (0);
}




int _choice(const char *format, int *p, va_list args)
{
	const char *str;
	char c;
	int i;
	unsigned int binary;

	switch (*format)
	{
		case '%':
			_putchar('%');
			(*p)++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			while (*str)
			{
				_putchar(*str);
				(*p)++;
				str++;
			}
			break;
		case 'c':
			c = va_arg(args, int);
			_putchar(c);
			(*p)++;
			break;
		case 'd':
		case 'i':
			i = va_arg(args, int);
			for_num(i, p);
			break;
		case 'b':
			binary  = va_arg(args, unsigned int);
			for_binary(binary, p);
			break;
		default:
			_putchar('%');
			(*p) += 2;
			break;
	}
	return (0);
}

int _printf(const char *format, ...)
{
	int printed = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			_choice(format, &printed, args);
		}
		else
		{
			_putchar(*format);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
