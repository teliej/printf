#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define LOCAL_BUFFER_SIZE 1024


int for_binary(unsigned int binary, int *p, char *buff, int *buff_index)
{
	if (binary / 2 != 0)
		for_binary(binary / 2, p, buff, buff_index);

	_putchar('0' + (binary % 2), buff, buff_index);

	(*p)++;

	return (0);
}

int for_num(int i, int *p, char *buff, int *buff_index)
{
	unsigned int j;

	if (i < 0)
	{
		_putchar('-', buff, buff_index);
		(*p)++;
		j = -i;
	}
	else
		j = i;

	if (j / 10 != 0)
		for_num(j / 10, p, buff, buff_index);

	_putchar(j % 10 + '0', buff, buff_index);
	(*p)++;
	return (0);
}




int _choice(const char *format, int *p, va_list args,  char *buff,
		int *buff_index)
{
	switch (*format)
	{
		case '%':
			for_percent(p, buff, buff_index);
			break;
		case 's':
			for_short(va_arg(args, char *), p, buff, buff_index);
			break;
		case 'c':
			for_char(va_arg(args, int), p, buff, buff_index);
			break;
		case 'd':
		case 'i':
			for_integer(va_arg(args, int), p, buff, buff_index);
			break;
		case 'b':
			for_to_binary(va_arg(args, unsigned int), p, buff, buff_index);
			break;
		case 'u':
			for_unsign(va_arg(args, unsigned int), p, buff, buff_index);
			break;
		case 'o':
			for_octal(va_arg(args, unsigned int), p, buff, buff_index);
			break;
		case 'x':
			for_lower_hex(va_arg(args, unsigned int), p, buff, buff_index);
			break;
		case 'X':	
			for_upper_hex(va_arg(args, unsigned int), p, buff, buff_index);
			break;
		default:
			_putchar('%', buff, buff_index);
			(*p) += 2;
			break;
	}
	return (0);
}

int out_buff(const char *buffer, int length)
{
	int outted = 0;

	while (outted < length)
	{
		int i = write(1, (buffer + outted), (length - outted));

		if (i < 0)
		{
			return -1;
		}
		outted += i;
	}
	return outted;
}



int _printf(const char *format, ...)
{
	int printed = 0;
	va_list args;
	char buff[LOCAL_BUFFER_SIZE];
	int buff_index = 0;
	
	va_start(args,format);
	
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			_choice(format, &printed, args, buff, &buff_index);
		}
		else
		{
			if(buff_index == (LOCAL_BUFFER_SIZE - 1))
			{
				if (out_buff(buff, buff_index) < 0)
				{
					va_end(args);
					return -1;
				}
				printed += buff_index;
				buff_index = 0;
			}
			buff[buff_index++] = *format;
		}
		format++;
	}
	if (buff_index > 0) {
	if (out_buff(buff, buff_index) < 0) {
            va_end(args);
            return -1;
	}
	printed += buff_index;
	}
	va_end(args);
	return (printed);
}
