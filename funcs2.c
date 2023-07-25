#include "main.h"

/**
 * for_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int for_reverse(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, p = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++);

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		p++;
	}
	return (p);
}

/**
 * for_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int for_pointer(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char Qir = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long rest_d;
	char contain_er[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	rest_d = (unsigned long)addrs;

	while (rest_d > 0)
	{
		buff[index--] = contain_er[rest_d % 16];
		rest_d /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		Qir = '+', length++;
	else if (flags & F_SPACE)
		Qir = ' ', length++;

	index++;

	/*return (write(1, &buff[i], BUFF_SIZE - i - 1));*/
	return (do_pointer(buff, index, length,
		width, flags, padd, Qir, padd_start));
}

/**
 * for_hex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int for_hex(va_list args, char contain_er[], char buff[],
	int flags, char lol, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number;
	unsigned long int all_num;

    number = va_arg(args, unsigned long int);
    all_num = number;
	UNUSED(width);

	number = turn_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = contain_er[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && all_num != 0)
	{
		buff[i--] = lol;
		buff[i--] = '0';
	}

	i++;

	return (do_unsgnd(0, i, buff, flags, width, precision, size));
}

/**
 * for_nonprintable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_nonprintable(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int course = 0;
    int i = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + course] = str[i];
		else
			course += add_hexa_code(str[i], buff, i + course);

		i++;
	}

	buff[i + course] = '\0';

	return (write(1, buff, i + course));
}

/**
 * for_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_hex_upper(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	return (for_hex(args, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}
