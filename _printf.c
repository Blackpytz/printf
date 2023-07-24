#include "main.h"
/**
* _printf - function that produces output according to a format
* @format: pointer to a character string
* Return: the number of characters printed(excludeing the null byte used
* to end output to strings or NULL if format is NULL.
*/
int _printf(const char *format, ...)
{
	int (*f)(va_list), i = 0, value = 0, count = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0' && format)
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count += value;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				value = f(ap);
				count = count + value;
				i = i + 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i], 1);
				count += count + value;
				i += 2;
				continue;
			}
		}
	}
	va_end(ap);
	return (count);
}
