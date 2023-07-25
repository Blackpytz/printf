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
/**
* rot13 - Performs ROT1e encryption on a string.
* @str: The input string to be encrypted.
* @len: len of the string.
*
* Return: Pointer to the ROT13'ed string.
*/
char *rot13(char *str, int len)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j;
	char *result, is_rotated;

	result = (char *)malloc(len + 1);

	if (result == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		is_rotated = 0;
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alphabet[j])
			{
				result[i] = rot13[j];
				is_rotated = 1;
				break;
			}
		}
		if (!is_rotated)
			result[i] = str[i];
	}
	result[i] = '\0';

	return (result);
}

/**
* print_rot - function that prints the rot13'ed string
* @ap: Variadic function
*
* Return: length of the string printed
*/
int print_rot(va_list ap)
{
	char *str, *rot13_str;
	int count = 0, len = 0;

	str = va_arg(ap, char *);

	while (str[len] != '\0')
		len++;
	if (str != NULL)
	{
		rot13_str = rot13(str, len);
		while (*rot13_str)
		{
			write(1, rot13_str, 1);
			rot13_str++;
			count++;
		}
		return (count);
	}
	return (0);
}
