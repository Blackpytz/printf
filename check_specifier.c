#include "main.h"

/**
* check_specifier - a pointer to a function that checks the conversion specifer
* @s: pointer to a char to be checked
*
* Return: pointer to the corresponding function.
*/
int (*check_specifier(const char *s))(va_list)
{
	int i;
	func_t my_struct[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{"d", print_int},
		{"i", print_int},
		{"r", print_reversed_str},
		{"R", print_rot},
		{NULL, NULL}
	};

	for (i = 0; my_struct[i].type != NULL; i++)
	{
		if (*(my_struct[i].type) == *s)
			return (my_struct[i].f);
	}
	return (NULL);
}
