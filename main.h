fndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_binary(va_list args);
int print_pointer(va_list args);
int print_rot13(va_list args);
int print_rev(va_list args);
int print_S(va_list args);

#endif /* MAIN_H */
