#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * write_char - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: The number of characters written.
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_str - Writes a string to stdout.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */
int write_str(const char *str)
{
	int count = 0;

	while (*str)
	{
		count += write_char(*str);
		str++;
	}

	return (count);
}

/**
 * write_int - Writes an integer to stdout.
 * @num: The integer to write.
 *
 * Return: The number of characters written.
 */
int write_int(int num)
{
	char buffer[12]; /* Sufficient for INT_MIN */
	int len = 0;

	if (num < 0)
	{
		write_char('-');
		num = -num;
	}

	if (num == 0)
	{
		return (write_char('0'));
	}

	while (num > 0)
	{
		buffer[len] = num % 10 + '0';
		num /= 10;
		len++;
	}

	int count = 0;

	while (len > 0)
	{
		len--;
		count += write_char(buffer[len]);
	}

	return (count);
}

