#include <stdarg.h>
#include "main.h"
#include <stddef.h>



void _choice_two(const char *format, int *p, va_list args, char *buff, int *buff_index, int *flag)
{
    switch (*format)
    {
        case 'X':
            for_hex(va_arg(args, unsigned int), 1, p, buff, buff_index, flag);
            break;
        case 'p':
            for_ptr(va_arg(args, void *), p, buff, buff_index);
            break;
        case 'S':
            for_str_non(va_arg(args, char *), p, buff, buff_index);
            break;
        case 'x':
            for_hex(va_arg(args, unsigned int), 0, p, buff, buff_index, flag);
            break;
        default:
            _putchar('%', buff, buff_index);
            _putchar(*format, buff, buff_index);
            (*p) += 2;
            break;
    }
}


void _choice(const char *format, int *p, va_list args, char *buff, int *buff_index, int *flag)
{
    switch (*format)
    {
        case 's':
            for_str_non(va_arg(args, char *), p, buff, buff_index);
            break;
        case '%':
            _putchar('%', buff, buff_index);
            (*p)++;
            break;
        case 'b':
            for_binary(va_arg(args, unsigned int), p, buff, buff_index);
            break;
        case 'u':
            for_ui(va_arg(args, unsigned int), p, buff, buff_index, flag);
            break;
        case 'o':
            for_octal(va_arg(args, unsigned int), p, buff, buff_index, flag);
            break;
	case 'c':
            _putchar(va_arg(args, int), buff, buff_index);
            (*p)++;
            break;	
        case 'd':
        case 'i':
            for_integer(va_arg(args, int), p, buff, buff_index, flag);
            break;
        default:
            _choice_two(format, p, args, buff, buff_index, flag);
    }
}



/**
 * _printf - Custom printf function.
 *
 * Description: This function produces formatted output according to the given format.
 * It supports the following conversion specifiers: c, s, %, u, o, x, X.
 * The function uses a local buffer to minimize the number of write calls for performance.
 *
 * @format: A character string containing zero or more directives.
 * @...: Variable arguments to be formatted.
 *
 * Returns: The number of characters printed (excluding the null byte used to end output to strings).
 *          Returns -1 on error or if the format is invalid.
 */
int _printf(const char *format, ...)
{
    int printed = 0; /** Variable to keep track of the total characters printed */
    int buff_index = 0; /** Current index in the buffer */
    char buff[BUFFER_SIZE]; /** Buffer to store formatted output */
    int flag = 0; /** check for any flags in the format specifier */
    va_list args; /** Argument list for variable arguments */

    /** Check for invalid format */
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return -1;
    /** Initialize the argument list */
    va_start(args, format);
    /** Loop through the format string */
    while (*format)
    {
        if (*format != '%') /** Regular character, not a format specifier */
        {
            _putchar(*format, buff, &buff_index);
            printed++;
        }
        else
        {
            format++; /** Move past the '%' */
            flag = see_flags(format);
	    if (flag)
		format++;
            _choice(format, &printed, args, buff, &buff_index, &flag);
        }
        format++;
    }
    /** Flush any remaining characters in the buffer */
    if (buff_index > 0)
        with_write(buff, &buff_index);

    /** Clean up the argument list */
    va_end(args);
    return printed; /** Return the total number of characters printed */
}

