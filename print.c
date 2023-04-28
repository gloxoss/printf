#include "main.h"


int _printf(const char *format, ...)
{
	// Variable declarations
int m, printed_cs = 0, flags, width, precision, size, printed;
int buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
// Check if the format string is NULL
if (format == NULL)
return (-1);
// Initialize the variable argument list
va_start(list, format);
// Iterate through the format string
for (m = 0; format && format[m] != '\0'; m++)
{
// If the current character is not a format specifier, add it to the buffer
if (format[m] != '%')
{
buffer[buff_ind++] = format[m];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_cs++;
}
// If the current character is a format specifier, handle it
else
{
// Print the buffer if it contains any characters
print_buffer(buffer, &buff_ind);
// Get the flags, width, precision, and size from the format string
flags = get_flags(format, &m);
width = get_width(format, &m, list);
precision = get_precision(format, &m, list);
size = get_size(format, &m);
// Increment the format index to get to the specifier character
++m;

// Handle the format specifier and add the result to the buffer
printed = handle_print(format, &m, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_cs += printed;
}
}

// Print the buffer if it contains any characters
print_buffer(buffer, &buff_ind);
//Clean up the variable argument list
va_end(list);

// Return the number of characters printed
return (printed_cs);
}
/**
* print_buffer - Prints the contents of the buffer if it exists
* @buffer: Array of characters
* @buff_ind: Pointer to the buffer index representing the length
* Description: This function prints the contents of the buffer
* if it exists and resets the buffer index.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
