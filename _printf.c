#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;
case 's':
count += _printf(va_arg(args, char *));
break;
case '%':
_putchar('%');
count++;
break;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}

