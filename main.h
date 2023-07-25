#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct format fmt_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);

int work_command(const char *format, int *i,
va_list list, char buff[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int for_char(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_string(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_percent(va_list types, char buff[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int for_integer(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_binary(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_octal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_hex_lower(va_list types, char buff[],
	int flags, int width, int precision, int size);
int for_hex_upper(va_list types, char buff[],
	int flags, int width, int precision, int size);

int for_hex(va_list types, char map_to[],
char buff[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int for_nonprintable(va_list types, char buff[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int for_pointer(va_list types, char buff[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int for_flags(const char *format, int *i);
int for_width(const char *format, int *i, va_list list);
int for_precision(const char *format, int *i, va_list list);
int for_size(const char *format, int *i);

/*Function to print string in reverse*/
int for_reverse(va_list types, char buff[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int for_rot13str(va_list types, char buff[],
	int flags, int width, int precision, int size);

/* width handler */
int for_written_char(char c, char buff[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buff[],
	int flags, int width, int precision, int size);
int with_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int do_pointer(char buff[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int do_unsgnd(int is_negative, int ind,
char buff[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int add_hexa_code(char, char[], int);
int is_digit(char);

long int convert_num_size(long int num, int size);
long int turn_unsgnd(unsigned long int num, int size);

#endif

