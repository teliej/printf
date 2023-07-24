#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "main.h"


void see_string(char *str, int *p, char *buff, int *buff_index)
{
	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str, buff, buff_index);
		str++;
		(*p)++;
	}

}


void for_ptr(void* ptr, int* p, char* buff, int* buff_index)
{
    int i, num_chars = 0, null_str_len;
    uintptr_t ptr_val, temp_val;
    unsigned int digit;
    const char *null_str;
    if (ptr == NULL) {
        null_str = "(NULL)";
        null_str_len = 6;

        for (i = 0; i < null_str_len; i++) {
            buff[(*buff_index)++] = null_str[i];
        }
        (*p) += null_str_len - 1;
    } else {
        ptr_val = (uintptr_t)ptr;
        temp_val = ptr_val;

        if (ptr_val == 0)
            num_chars = 1;
        else {
            while (temp_val) {
                temp_val /= 16;
                num_chars++;
            }
        }
        if ((*buff_index) + num_chars + 2 >= BUFFER_SIZE) {
            with_write(buff, buff_index);
            (*buff_index) = 0;
        }
        buff[(*buff_index)++] = '0';
        buff[(*buff_index)++] = 'x';
        for (i = num_chars - 1; i >= 0; i--) {
            digit = ptr_val % 16;
            if (digit < 10)
                buff[(*buff_index) + i] = '0' + digit;
            else
                buff[(*buff_index) + i] = 'a' + digit - 10;
            ptr_val /= 16;
        }
        buff[(*buff_index) + num_chars] = '\0';
        (*buff_index) += num_chars;
        (*p) += num_chars + 2;
    }
}





void for_str_non(char* str, int* p, char* buff, int* buff_index) {
    while (*str) {
        if (*str < 32 || *str >= 127) {
            buff[(*buff_index)++] = '\\';
            buff[(*buff_index)++] = 'x';
            buff[(*buff_index)++] = "0123456789ABCDEF"[(*str >> 4) & 0xF];
            buff[(*buff_index)++] = "0123456789ABCDEF"[*str & 0xF];

            (*p) += 4;
        } else {
            buff[(*buff_index)++] = *str;
            (*p)++;
        }

        str++;
    }
}



int see_flags(const char *format)
{
	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
		{
			return (1);
		}

		else if (*format == ' ')
		{
			return (2);
		}

		else if (*format == '#')
		{
			return (3);
		}

	}

	return (0);
}
