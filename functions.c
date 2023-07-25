#include "main.h"

/**
* print_char - prints a single character
* @ap: variadic parameter
*
* Return: a single character printed
*/
int print_char(va_list ap)
{
	char c;
	int count = 0;

	c = (char)va_arg(ap, int);
	if (c)
	{
		count = write(1, &c, 1);
		return (count);
	}
	return (0);
}

/**
* print_str - prints a string
* @ap: variadic parameter
*
* Return: number of characters printed
* or NULL if not successful
*/
int print_str(va_list ap)
{
	char *str;
	int count = 0;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (0);
	}
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

/**
* print_cent - prints percent sign
* @ap: variadic parameter
*
* Return: number of characters printed
*/
int print_cent(va_list ap)
{
	char c;
	int count = 0;
	(void)ap;

	c = '%';

	count = write(1, &c, 1);
	return (count);
}
