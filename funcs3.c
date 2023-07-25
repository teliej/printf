#include "main.h"


/**
 * for_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int for_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int j, curr_i;
	const char FLAGS_sign[] = {'-', '+', '0', '#', ' ', '\0'};
	int flags = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_sign[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_sign[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_sign[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}


/**
 * for_rot13str - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int for_rot13str(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j;
	char k;
	char *str;
	int p = 0;
	char out_char[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char in_char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	str = va_arg(args, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in_char[j]; j++)
		{
			if (in_char[j] == str[i])
			{
				k = out_char[j];
				write(1, &k, 1);
				p++;
				break;
			}
		}
		if (!in_char[j])
		{
			k = str[i];
			write(1, &k, 1);
			p++;
		}
	}
	return (p);
}

/**
 * for_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int for_precision(const char *format, int *i, va_list args)
{
	int j = -1;
	int k = *i + 1;

	if (format[k] != '.')
		return (j);

	j = 0;

	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			j *= 10;
			j += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			j = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (j);
}

/**
 * for_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int for_size(const char *format, int *i)
{
	int j = 0;
	int k = *i + 1;

	if (format[k] == 'l')
		j = S_LONG;
	else if (format[k] == 'h')
		j = S_SHORT;

	if (j == 0)
		*i = k - 1;
	else
		*i = k;

	return (j);
}
