#include "main.h"

/**
 * for_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_octal(va_list args, char buff[],
	int flags, int width, int precision, int size)
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
		buff[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && all_num != 0)
		buff[i--] = '0';

	i++;

	return (do_unsgnd(0, i, buff, flags, width, precision, size));
}


/**
 * for_hex_lower - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_hex_lower(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	return (for_hex(args, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}

/**
 * for_integer - Print int
 * @args: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int for_integer(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int kane = 0;
	long int Qir = va_arg(args, long int);
	unsigned long int num;

	Qir = convert_num_size(Qir, size);

	if (Qir == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)Qir;

	if (Qir < 0)
	{
		num = (unsigned long int)((-1) * Qir);
		kane = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(kane, i, buff, flags, width, precision, size));
}

/**
 * for_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int for_unsigned(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number;
    
    number = va_arg(args, unsigned long int);

	number = turn_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (do_unsgnd(0, i, buff, flags, width, precision, size));
}


/**
 * for_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int for_binary(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, n, add_all;
	unsigned int a[32];
	int p;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	a[0] = n / j;
	for (i = 1; i < 32; i++)
	{
		j /= 2;
		a[i] = (n / j) % 2;
	}
	for (i = 0, add_all = 0, p = 0; i < 32; i++)
	{
		add_all += a[i];
		if (add_all || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			p++;
		}
	}
	return (p);
}
