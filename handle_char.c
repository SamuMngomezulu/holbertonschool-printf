#include "main.h"

/**
 * handle_char - Handles %c
 * @args: argument list
 * Return: number of characters printed
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}
