#include "main.h"



/**
 * for_percent - Prints a percent sign
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_percent(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}



/**
 * for_string - Prints a string
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_string(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int length = 0;
    int i;
	char *str = va_arg(args, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}





/**
 * for_char - Prints a char
 * @args: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_char(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char i = va_arg(args, int);

	return (for_written_char(i, buff, flags, width, precision, size));
}

/**
 * out_buff - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void out_buff(char buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buff[0], *buff_index);

	*buff_index = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i;
    int printed, written_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				out_buff(buff, &buff_index);
			/* write(1, &format[i], 1);*/
			written_chars++;
		}
		else
		{
			out_buff(buff, &buff_index);
			flags = for_flags(format, &i);
			width = for_width(format, &i, list);
			precision = for_precision(format, &i, list);
			size = for_size(format, &i);
			++i;
			printed = work_command(format, &i, list, buff,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			written_chars += printed;
		}
	}

	out_buff(buff, &buff_index);

	va_end(list);

	return (written_chars);
}
