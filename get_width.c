#include "main.h"

/**
 * get_width - Extracts the width argument from the format string or from variadic arguments.
 *
 * @format: A pointer to the format string.
 * @i: A pointer to the current index in the format string.
 * @ap: The va_list of variadic arguments.
 *
 * Return: The width argument, or 0 if it was not found.
 */
int get_width(const char *format, int *i, va_list ap)
{
    int width = 0; // The width argument to be extracted.
    int curr_i = *i + 1; // The current index in the format string.

    for (; format[curr_i] != '\0'; curr_i++) {
        if (is_digit(format[curr_i])) {
            // Accumulate digits to calculate the width argument.
            width *= 10;
            width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*') {
            // Extract the width argument from variadic arguments.
            curr_i++;
            width = va_arg(ap, int);
            break;
        }
        else {
            // Stop searching for the width argument if another specifier is found.
            break;
        }
    }

    // Update the current index in the format string.
    *i = curr_i - 1;

    return width;
}
