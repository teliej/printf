#include "main.h"
#include <math.h>


void for_string(const char *str, int *p, char *buff, int *buff_index)
{
    while (*str)
    {
        _putchar(*str, buff, buff_index);
        (*p)++;
        str++;
    }
}

void for_integer(int num, int *p, char *buff, int *buff_index, int *flag)
{
    unsigned int n;

    if (*flag == 1 && num >= 0)
    {
        buff[(*buff_index)++] = '+';
        (*p)++;
        *flag = 0;
    }
    else if (*flag == 2 && num >= 0)
    {
        buff[(*buff_index)++] = ' ';
        (*p)++;
        *flag = 0;
    }

    if (num < 0)
    {
        _putchar('-', buff, buff_index);
        (*p)++;
        n = -num;
    }
    else
        n = num;

    if (n / 10 != 0)
        for_integer(n / 10, p, buff, buff_index, flag);

    _putchar(n % 10 + '0', buff, buff_index);
    (*p)++;
}

void for_binary(unsigned int b, int *p, char *buff, int *buff_index)
{
    if (b / 2 != 0)
        for_binary(b / 2, p, buff, buff_index);

    _putchar('0' + (b % 2), buff, buff_index);
    (*p)++;
}

void for_ui(unsigned int u, int *p, char *buff, int *buff_index, int *flag)
{
    if (*flag == 1)
    {
        buff[(*buff_index)++] = '+';
        (*p)++;
        *flag = 0;
    }
    else if (*flag == 2)
    {
        buff[(*buff_index)++] = ' ';
        (*p)++;
        *flag = 0;
    }

    if (u / 10 != 0)
        for_ui(u / 10, p, buff, buff_index, flag);

    _putchar(u % 10 + '0', buff, buff_index);
    (*p)++;
}

void for_octal(unsigned int o, int *p, char *buff, int *buff_index, int *flag)
{
    if (*flag == 3)
    {
        buff[(*buff_index)++] = '0';
        (*p)++;
        *flag = 0;
    }

    if (o / 8 != 0)
        for_octal(o / 8, p, buff, buff_index, flag);

    _putchar(o % 8 + '0', buff, buff_index);
    (*p)++;
}

void for_hex(unsigned int i, int uppercase, int *p, char *buff, int *buff_index, int *flag)
{
    char *str;

    if (*flag == 3)
    {
        buff[(*buff_index)++] = '0';
        buff[(*buff_index)++] = 'x';
        (*p) += 2;
        *flag = 0;
    }

    if (uppercase)
        str = "0123456789ABCDEF";
    else
        str = "0123456789abcdef";

    if (i / 16 != 0)
        for_hex(i / 16, uppercase, p, buff, buff_index, flag);

    _putchar(str[i % 16], buff, buff_index);
    (*p)++;
}

