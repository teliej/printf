#include <unistd.h>
#include "main.h"

/**
 * with_write - Helper function to write the buffer to STDOUT_FILENO
 * @buff: The buffer containing characters to be printed
 * @buff_index: The current index in the buffer
 */
void with_write(char *buff, int *buff_index)
{
    /** Write the buffer contents to the standard output */
    write(1, buff, *buff_index);
}

/**
 * _putchar - A custom function to store characters in the buffer.
 *
 * Description: It stores single characters in the buffer.
 * @YC_c: The character to be stored
 * @buff: The buffer to store characters
 * @buff_index: The current index in the buffer
 */
void _putchar(char YC_c, char *buff, int *buff_index)
{
    buff[*buff_index] = YC_c;
    (*buff_index)++;

    /** Check if the buffer is full*/
    if (*buff_index >= BUFFER_SIZE - 1)
    {
        /** Write the buffer to the standard output*/
        with_write(buff, buff_index);
        /** Reset the buffer index*/
        *buff_index = 0;
    }
}
