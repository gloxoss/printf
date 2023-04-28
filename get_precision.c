#include <stdbool.h>
#include <stdarg.h>
#include "main.h"


/**
 * get_precision - Parses the precision value from a format string.
 * @format: The format string to parse.
 * @start: The starting position in the format string to parse from.
 * @ap: The va_list of arguments.
 *
 * Return: The precision value if found, or -1 if not found.
 */
int get_precision(const char *format, size_t start, va_list ap)
{
    int precision = -1;
    bool has_precision = false;

    for (size_t i = start; format[i] != '\0'; i++) {
        if (format[i] == '.') {
            has_precision = true;
            continue;
        }

        if (has_precision) {
            if (format[i] == '*') {
                precision = va_arg(ap, int);
                break;
            }

            if (format[i] >= '0' && format[i] <= '9') {
                if (precision == -1) {
                    precision = 0;
                }

                precision = precision * 10 + (format[i] - '0');
            } else {
                break;
            }
        }
    }

    return precision;
}
