#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned
 * and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom implementation of printf.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char ch;

	va_start(args, format);

	while ((ch = *format++) != '\0')
	{
		if (ch != '%')
		{
			_putchar(ch);
			count++;
		}
		else
		{
			ch = *format++;
			switch (ch)
			{
				case 'c':
				{
					char c = (char) va_arg(args, int);

					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *str = va_arg(args, const char*);

					while (*str != '\0')
					{
						_putchar(*str++);
						count++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count++;
					break;
				}
				default:
					break;
			}
		}
	}

	va_end(args);
	return (count);
}

