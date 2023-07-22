#ifndef _MAIN_H_
#define _MAIN_H_

int _putchar(char c);
int _printf(const char *format, ...);
int for_binary(unsigned int binary, int *p);
int for_num(int i, int *p);
int for_percent(int *p);
int for_short(const char *str, int *p);
int for_char(char c, int *p);
int for_integer(int i, int *p);
int for_to_binary(unsigned int binary, int *p);
int for_unsign(unsigned int i, int *p);
int for_octal(unsigned int j, int *p);
void for_lower_hex(unsigned int k, int *p);
void for_upper_hex(unsigned int k, int *p);

#endif
