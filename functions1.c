#include "main.h"

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
		reversedbuf[j++] = buf[i];
	write(1, reversedbuf, j);

	return (count);
}

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
