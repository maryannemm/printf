#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include "print_functions.h"
#include "write_functions.h"
/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
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
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, const char *));
					break;
				case '%':
					count += print_char('%');
					break;
				case 'd':
				case 'i':
					count += print_int(va_arg(args, int));
					break;
				default:
					count += print_char('%');
					count += print_char(*format);
					break;
			}
		}
		else
		{
			count += print_char(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

