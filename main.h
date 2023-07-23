#ifndef _MAIN_H_
#define _MAIN_H_

int _putchar(char c, char *buff, int *buff_index);
int _printf(const char *format, ...);
int for_binary(unsigned int binary, int *p, char *buff, int *buff_index);
int for_num(int i, int *p, char *buff, int *buff_index);
int for_percent(int *p, char *buff, int *buff_index);
int for_short(const char *str, int *p, char *buff, int *buff_index);
int for_char(char c, int *p, char *buff, int *buff_index);
int for_integer(int i, int *p, char *buff, int *buff_index);
int for_to_binary(unsigned int binary, int *p, char *buff, int *buff_index);
int for_unsign(unsigned int i, int *p, char *buff, int *buff_index);
int for_octal(unsigned int j, int *p, char *buff, int *buff_index);
void for_lower_hex(unsigned int k, int *p, char *buff, int *buff_index);
void for_upper_hex(unsigned int k, int *p, char *buff, int *buff_index);

#endif
