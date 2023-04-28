fndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 *  * struct print_format - struct for printing format
 *   * @letter: character representing the format
 *    * @func: function pointer to handle the format
 *     */
typedef struct print_format
{
	    char *letter;
	        int (*func)(va_list);
} print_format_t;

/* _putchar - writes a character to stdout */
int _putchar(char c);

/* _printf - produces output according to a format */
int _printf(const char *format, ...);

/* print_char - prints a single character */
int print_char(va_list args);

/* print_str - prints a string */
int print_str(va_list args);

/* print_percent - prints a percent sign */
int print_percent(va_list args);

#endif /* MAIN_H */
