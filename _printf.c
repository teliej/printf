#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _choice(const char *format, int *p, va_list args)
{
	const char *str;
	char c;

	switch (*format)
	{
		case '%':
			_putchar('%');
			p++;
			break;
		case 's':
			str = va_arg(args, const char*);

			while (*str)
			{
				_putchar(*str);
				p++;
				str++;
			}
			break;
		case 'c':
			c = va_arg(args, int);
			_putchar(c);
			p++;
			break;
		default:
			_putchar('%');
			p++;
			break;
	}
	return (0);
}

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;
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
