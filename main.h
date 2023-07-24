#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


void _putchar(char c, char *buff, int *buff_index);
void with_write(char *buff, int *buff_index);

int _printf(const char *format, ...);

void see_string(char *str, int *p, char *buff, int *buff_index);
int see_flags(const char *format);
void for_integer(int num, int *p, char *buff, int *buff_index, int *flag);
void for_binary(unsigned int b, int *p, char *buff, int *buff_index);
void for_ui(unsigned int u, int *p, char *buff, int *buff_index, int *flag);
void for_octal(unsigned int o, int *p, char *buff, int *buff_index, int *flag);
void for_hex(unsigned int h, int uppercase, int *p, char *buff, int *buff_index, int *flag);
void for_str_non(char *s, int *p, char *buff, int *buff_index);
void for_ptr(void *ptr, int *p, char *buff, int *buff_index);

void _choice(const char *format, int *p, va_list args, char *buff, int *buff_index, int *flag);
void _choice_two(const char *format, int *p, va_list args, char *buff, int *buff_index, int *flag);

#endif
