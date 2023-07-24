#include "main.h"

/**
* _putchar - prints a single char
* @c: character to be printed
*
* Return: the character written if successful
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
