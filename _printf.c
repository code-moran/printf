#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - Custom putchar function.
 * @c: Character to be printed.
 *
 * Return: On success, return the character printed, otherwise, return EOF.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Custom printf function.
 * @format: Format string with optional conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move to the character after '%' */

			/* Handle conversion specifiers */
			switch (*format)
			{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				count += printf("%s", va_arg(args, char *));
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				/* Unknown conversion specifier, ignore */
				break;
			}
		}
		else
		{
			/* Regular character, just print it */
			count += _putchar(*format);
		}

		format++; /* Move to the next character in the format string */
	}

	va_end(args);

	return (count);
}

