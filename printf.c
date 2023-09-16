#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0; /* To keep track of the number of characters printed */

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */

            /* Handle conversion specifiers */
            switch (*format)
            {
            case 'c':
            {
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            break;
            case 's':
            {
                const char *str = va_arg(args, const char *);
                while (*str)
                {
                    count += write(1, str, 1);
                    str++;
                }
            }
            break;
            case '%':
                count += write(1, "%", 1);
                break;
            case 'd':
            case 'i':
            {
                int num = va_arg(args, int);
                char buffer[12]; /* Assuming a maximum of 11 digits for an int */
                int length = 0;

                if (num < 0)
                {
                    count += write(1, "-", 1);
                    num = -num;
                }

                if (num == 0)
                {
                    buffer[length++] = '0';
                }
                else
                {
                    while (num > 0)
                    {
                        buffer[length++] = '0' + (num % 10);
                        num /= 10;
                    }
                }

                while (length > 0)
                {
                    count += write(1, &buffer[--length], 1);
                }
            }
            break;
            default:
                /* Unsupported conversion specifier, just print it as is */
                count += write(1, "%", 1);
                count += write(1, format, 1);
                break;
            }
        }
        else
        {
            /* Regular character, just print it */
            count += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return (count);
}

