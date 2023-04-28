#include <stddef.h>

/**
 * get_size - Parses the size modifier from a format string.
 * @format: The format string to parse.
 * @start: The starting position in the format string to parse from.
 *
 * Return: The size modifier value if found, or 0 if not found.
 */
int get_size(const char *format, size_t start)
{
    int size = 0;

    if (format[start] == 'l') {
        size = S_LONG;
    } else if (format[start] == 'h') {
        size = S_SHORT;
    }

    return size;
}
