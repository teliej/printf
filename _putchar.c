#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include "main.h"

#define LOCAL_BUFFER_SIZE 1024

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c, char *buff, int *buff_index)
{
	buff[(*buff_index)++] = c;
	return (0);
}
