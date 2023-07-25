#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * for_written_char - functions that Prints a string
 * @c: char.
 * @buff: Buffer array
 * @flags: finds active flags.
 * @width: get width.
 * @precision: precision specifier.
 * @size: Size specifier.
 *
 * Return: returns the number of chars printed.
 */
int for_written_char(char c, char buff[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buff's right */
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = padding;

		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @if_negative: Lista of arguments
 * @index: char.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int if_negative, int index, char buff[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padding = ' ', Qir = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (if_negative)
		Qir = '-';
	else if (flags & F_PLUS)
		Qir = '+';
	else if (flags & F_SPACE)
		Qir = ' ';

	return (with_num(index, buff, flags, width, precision,
		length, padding, Qir));
}

/**
 * with_num - prints numbers using a bufffer
 * @index: Index at start of a buffer.
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @jin: Extra char
 *
 * Return: returns the number of printed chars.
 */
int with_num(int index, char buff[],
	int flags, int width, int precision,
	int length, char padding, char jin)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = padding = ' '; /* width is displayed with padding ' ' */
	if (precision > 0 && precision < length)
		padding = ' ';
	while (precision > length)
		buff[--index] = '0', length++;
	if (jin != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (flags & F_MINUS && padding == ' ')/* Asign extra char to left of buff */
		{
			if (jin)
				buff[--index] = jin;
			return (write(1, &buff[index], length) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')/* extra char left of buff */
		{
			if (jin)
				buff[--index] = jin;
			return (write(1, &buff[1], i - 1) + write(1, &buff[index], length));
		}
		else if (!(flags & F_MINUS) && padding == '0')/* extra char to left of padding */
		{
			if (jin)
				buff[--padd_start] = jin;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[index], length - (1 - padd_start)));
		}
	}
	if (jin)
		buff[--index] = jin;
	return (write(1, &buff[index], length));
}

/**
 * do_unsgnd - Writes an unsigned number
 * @if_neg: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: returns a number of written chars.
 */
int do_unsgnd(int if_neg, int index,
	char buff[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - index - 1, i = 0;
	char padding = ' ';

	UNUSED(if_neg);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		buff[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buff[i] = padding;

		buff[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buff [buff>padding]*/
		{
			return (write(1, &buff[index], length) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of padding [padding>buff]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], length));
		}
	}

	return (write(1, &buff[index], length));
}

/**
 * do_pointer - prints a memory address.
 * @buff: Arrays of chars.
 * @index: Index of the start of the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: for the padding
 * @jin: for extra char
 * @padd_start: where padding should start
 *
 * Return: return a number of written chars.
 */
int do_pointer(char buff[], int index, int length,
	int width, int flags, char padding, char jin, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (flags & F_MINUS && padding == ' ')/* Asign extra char to left of buff */
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (jin)
				buff[--index] = jin;
			return (write(1, &buff[index], length) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padding == ' ')/* extra char to left of buff */
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (jin)
				buff[--index] = jin;
			return (write(1, &buff[3], i - 3) + write(1, &buff[index], length));
		}
		else if (!(flags & F_MINUS) && padding == '0')/* extra char to left of padding */
		{
			if (jin)
				buff[--padd_start] = jin;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[index], length - (1 - padd_start) - 2));
		}
	}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (jin)
		buff[--index] = jin;
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
