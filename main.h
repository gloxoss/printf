fndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

// Function prototypes
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
void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *m);
int get_width(const char *format, int *m, va_list list);
int get_precision(const char *format, int *m, va_list list);
int get_size(const char *format, int *m);
int handle_print(const char *format, int *m, va_list list,char buffer[], int flags, int width, int precision,int size);

#endif /* MAIN_H */
