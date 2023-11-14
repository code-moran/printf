#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: character string containing directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(args, int);
				printed_chars += print_number(n);
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					_putchar(*s);
					printed_chars++;
					s++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				printed_chars++;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * print_number - prints an integer
 * @n: The integer to be printed
 *
 * Return: the number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

