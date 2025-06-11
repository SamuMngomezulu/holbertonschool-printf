#include "main.h" /* For _putchar and _printf prototype */
#include <stdarg.h> /* Required for va_list, va_start, va_arg, va_end */
#include <stdlib.h> /* Required for NULL (for char * s_val = NULL check) */

/**
 * _print_string - Helper function to print a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
static int _print_string(char *s)
{
	int count = 0;

	/* If the string pointer is NULL, print "(null)" */
	if (s == NULL)
	{
		s = "(null)";
	}

	/* Iterate through the string and print each character using _putchar */
	while (*s)
	{
		_putchar(*s);
		count++;
		s++;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string, composed of zero or more directives.
 * Handles: %c (character), %s (string), %% (literal percent).
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings). Returns -1 on error (e.g., NULL format,
 * or trailing % without a specifier).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;
	char char_val;
	char *string_val;

	/* Handle NULL format string as an error */
	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format); /* Initialize argument list */

	/* Iterate through the format string */
	while (format[i] != '\0')
	{
		if (format[i] == '%') /* Found a format specifier start */
		{
			i++; /* Move to the character after '%' */

			/* Handle cases where '%' is the last character or followed by NULL */
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1); /* Invalid format: trailing '%' */
			}

			switch (format[i])
			{
				case 'c':
					/* Retrieve character argument (promoted to int in va_arg) */
					char_val = (char)va_arg(args, int);
					_putchar(char_val);
					printed_chars++;
					break;
				case 's':
					/* Retrieve string argument */
					string_val = va_arg(args, char *);
					printed_chars += _print_string(string_val);
					break;
				case '%':
					/* Print a literal '%' character */
					_putchar('%');
					printed_chars++;
					break;
				default:
					/* For unknown specifiers, print '%' and the character after it */
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
					break;
			}
		}
		else /* Not a format specifier, print character directly */
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++; /* Move to the next character in format string */
	}

	va_end(args); /* Clean up argument list */
	return (printed_chars);
}
