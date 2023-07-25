#include "main.h"

/**
 * for_width - finds the width for printing
 * @format: Formatted string.
 * @i: List of printed arguments.
 * @args: list of arguments.
 *
 * Return: returns the width.
 */
int for_width(const char *format, int *i, va_list args)
{
	int k;
	int wid_th = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			wid_th *= 10;
			wid_th += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			wid_th = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (wid_th);
}

/**
 * work_command - outputs an argument based on there types.
 * @format: Formatted string.
 * @args: List of printed arguments.
 * @index: the index.
 * @buff: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int work_command(const char *format, int *index, va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', for_char}, {'s', for_string}, {'%', for_percent},
		{'i', for_integer}, {'d', for_integer}, {'b', for_binary},
		{'u', for_unsigned}, {'o', for_octal}, {'x', for_hex_lower},
		{'X', for_hex_upper}, {'p', for_pointer}, {'S', for_nonprintable},
		{'r', for_reverse}, {'R', for_rot13str}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].format != '\0'; i++)
		if (format[*index] == fmt_types[i].format)
			return (fmt_types[i].fn(args, buff, flags, width, precision, size));

	if (fmt_types[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &format[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

