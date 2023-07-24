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
	int i = 0, count = 0;

	str = va_arg(ap, char *);
	if (str != NULL)
	{
		while (*(str + i) != '\0')
		{
			count += write(1, &str[i], 1);
			i++;
		}
		return (count);
	}
	return (0);
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

	c = (char)va_arg(ap, int);
	c = '%';

	count += write(1, &c, 1);
	return (count);
}

/**
* print_digit - prints integers
* @ap: variadic parameter
*
* Return: number of digits printed
*/
int print_int(va_list ap)
{
	int num, divisor;
	int count = 0;

	num = va_arg(ap, int);
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	divisor = 1;
	while (num / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		_putchar('0' + (num / divisor));
		count++;
		num %= divisor;
		divisor /= 10;
	}
	return (count);
}
