#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int num;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            num = va_arg(args, int);
            if (num < 0)
            {
                write(1, "-", 1);
                num = -num;
                count++;
            }
            count += write(1, num + '0', 1);
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return (count);
}

