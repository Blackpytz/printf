#include "main.h"

/**
* print_reversed_str - function that prints a reversed string
* @ap: variadic function
*
* Return: length of the string printed
*/
int print_reversed_str(va_list ap)
{
	char *str;
	int count, i;

	str = va_arg(ap, char *);
	count = 0;
	i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str)
	{
		str++;
		i++;
	}

	while (i > 0)
	{
		str--;
		write(1, str, 1);
		i--;
		count++;
	}
	return (count);
}
