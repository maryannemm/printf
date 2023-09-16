#include <stdarg.h>
#include "print_functions.h"
#include "write_functions.h"

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
    return write_char(c);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
    return write_str(str);
}

/**
 * print_int - Prints an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
{
    return write_int(num);
}

