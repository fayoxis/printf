#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
if (format == NULL)
return -1;
va_list list;
va_start(list, format);
int print_the_chars = 0;
int buff_ind = 0;
char buffer[BUFF_SIZE];
while (*format)
{
if (*format != '%')
{
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
buffer[buff_ind++] = *format++;
print_the_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
format++;
int flags = calculate_flags(format, &k);
int width = calculatePrintWidth(format, &currentIndex, list);
int precision = calculatePrecision(format, &currentIndex, list);
int size = determineSize(format, &currentIndex);
int printed = print_argument(format, &index, list, buffer, flags, width, precision, size);

if (printed == -1)
{
_putchar('%');
_putchar(*format);
print_the_chars += 2;
}
else
{
print_the_chars += printed;
}
}
}

print_buffer(buffer, &buff_ind);
va_end(list);

return print_the_chars;
}


/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: Pointer to the buffer index
 *
 * This function prints the characters stored in the buffer
 * by writing them to the standard output.
 * It starts printing from the beginning of the buffer
 * until the index specified by buff_ind.
 * The buff_ind is then reset to 0.
 */
void print_buffer(char buffer[], int *buff_ind)
{
write(1, buffer, *buff_ind);
*buff_ind = 0;
}

