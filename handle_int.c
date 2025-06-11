#include "main.h"

/**
 * handle_int - Handles %d and %i
 * @args: argument list
 * Return: number of characters printed
 */
int handle_int(va_list args)
{
	int n = va_arg(args, int);
	return (print_number(n));
}
