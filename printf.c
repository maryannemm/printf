#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
			case 'c':
				char_count += write(1, &va_arg(args, int), 1);
				break;
			case 's':
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					char_count += write(1, str, 1);
					str++;
				}
				break;
			}
			case '%':
				char_count += write(1, "%", 1);
				break;
			default:
				char_count += write(1, "%", 1);
				char_count += write(1, format, 1);
			}
		}
		else
		{
			char_count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);
	return (char_count);
}

