#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
int k = 0, currentIndex = 0, index = 0;
int flags, width, precision, size, printed;
va_list list;
int print_the_chars = 0;
int buff_ind = 0;
char buffer[BUFF_SIZE];
  
if (format == NULL)
return (-1);
va_start(list, format);
while (*format)
{
if (*format != '%')
{
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
buffer[buff_ind++] = *format;
print_the_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
format++;
flags = calculate_flags(format, &k);
width = calculatePrintWidth(format, &currentIndex, list);
precision = calculatePrecision(format, &currentIndex, list);
size = determineSize(format, &currentIndex);
printed = print_argument(format, &index, list, buffer,
flags, width, precision, size);
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
format++;
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (print_the_chars);
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
int i = 0;
while (i < *buff_ind)
{
_putchar(buffer[i]);
i++;
}
*buff_ind = 0;
}
