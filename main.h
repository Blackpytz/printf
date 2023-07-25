#ifndef MAIN_H
#define MAIN_H

#define BUFFER 1024 

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
struct func
{
	char *type;
	int (*f)(va_list);
};

/**
* struct func - struct type
* @func_t: struct variable
*/
typedef struct func func_t;

int _printf(const char *format, ...);
int (*check_specifier(const char *s))(va_list);

/*********** Functions ***********/

/* Fuctions prototype to print chars and strings */
int _putchar(char c);
int print_char(va_list);
int print_str(va_list);
int print_cent(va_list);

/* Fuctions to print number */
int print_int(va_list);

/* Fuction prototype to print reversed strings */
int print_reversed_str(va_list);

/* Function prototype to print the rot 13'ed string */
int print_rot(va_list);

#endif /* MAIN_H */
