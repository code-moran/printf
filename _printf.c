#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, the number of characters written. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing the conversion specifiers.
 *          Supported conversion specifiers: %c, %s, %%, %d, %i
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str_arg;
	int int_arg;
	char char_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char_arg = va_arg(args, int);
					printed_chars += _putchar(char_arg);
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					while (*str_arg)
					{
						printed_chars += _putchar(*str_arg);
						str_arg++;
					}
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					int_arg = va_arg(args, int);
					printed_chars += print_number(int_arg);
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_number - Helper function to print a number.
 * @n: The number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int divisor = 1;
	int printed_chars = 0;

	if (n < 0)
	{
		printed_chars += _putchar('-');
		n = -n;
	}

	while (n / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		printed_chars += _putchar((n / divisor) + '0');
		n %= divisor;
		divisor /= 10;
	}

	return (printed_chars);
}

