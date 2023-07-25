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

/**
* print_int - prints integers
* @ap: variadic parameter
*
* Return: number of digits printed
*/
int print_int(va_list ap)
{
	char buf[BUFFER], reversedbuf[BUFFER];
	int i, j, number, digit, index = 0, count = 0, isNegative = 0;

	number = va_arg(ap, int);

	/* Handle negative numbers */
	if (number < 0)
	{
		isNegative = 1;
		number = -number; /* Make the number positive for processing */
	}
	/* Handle the case of the number being zero explicitly */
	if (number == 0)
	{
		buf[index++] = '0';
	}
	else
	{
	/* Convert the number to characters from right to left */
		while (number > 0)
		{
			digit = number % 10;
			buf[index++] = '0' + digit;
			number /= 10;
		}
	}
	/* Add the negative sign if necessary */
	if (isNegative)
		buf[index++] = '-';
	/* Reverse the buffer to get the correct order of digits */
	j = 0;

	for (i = index - 1; i >= 0; i--)
	{
		reversedbuf[j++] = buf[i];
		count++;
	}
	write(1, reversedbuf, j);

	return (count);
}
