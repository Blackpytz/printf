#ifndef MAIN_H
#define MAIN_H

/* C programming header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
* struct func - struct type
* @type: pointer to an array of characters
* @f: pointer to a function.
*/
typedef struct func
{
	char *type;
	int (*f)(va_list);
} func_t;

int _printf(const char *format, ...);
int (*check_specifier(const char *s))(va_list);

/*********** Functions ***********/

/* Fuctions to print chars and strings */
int _putchar(char c);
int print_char(va_list);
int print_str(va_list);
int print_cent(va_list);

/* Fuctions to print number */
int print_int(va_list);

#endif /* MAIN_H */
