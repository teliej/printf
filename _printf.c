#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
	int printed = 0;
	va_list args;
	va_start(args, format);


	while (*format) {
		if (*format == '%') {
			format++;
			if (*format == '%') {
				putchar('%');
				printed++;
			} else if (*format == 'c') {
				char c = va_arg(args, int);
				putchar(c);
				printed++;
			} else if (*format == 's') {
				const char* str = va_arg(args, const char*);
				while (*str) {
					putchar(*str);
					printed++;
					str++;
				}
			}
		} else {
			putchar(*format);
			printed++;
		}
		format++;
	}

	va_end(args);
	return printed;
}
