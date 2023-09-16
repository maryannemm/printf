#include "holberton.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	if (format && args)
	{
		printed_chars = process_format(format, args);
	}

	va_end(args);
	return (printed_chars);
}

int process_format(const char *format, va_list args)
{
	int printed_chars = 0;

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else if (*(format + 1))
		{
			format++;
			if (*format == 'c')
				printed_chars += print_char(args);
			else if (*format == 's')
				printed_chars += print_string(args);
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_number(args);
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar('%');
			printed_chars++;
			break;
		}
		format++;
	}

	return (printed_chars);
}

