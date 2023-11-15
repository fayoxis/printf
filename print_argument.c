#include "main.h"

/**
 * print_argument - Prints an argument based on its type
 * @format: The formatted string in which to print the arguments.
 * @index: The index of the current character in the formatted string.
 * @arg_list: The list of arguments to be printed.
 * @output_buffer: The buffer array used for printing.
 * @flags: The active flags used for calculation.
 * @width: The width specifier.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed, or -1 if an error occurs.
 */
int print_argument(const char *format, int *index, va_list arg_list,
char output_buffer[], int flags, int width, int precision, int size)
{
int i = 0;
int unknown_len = 0;
form_t form_types[] = {
{'c', print_character}, {'s', printString}, {'%', printPercent},
{'i', printInteger}, {'d', printInteger}, {'b', printBinary},
{'u', printUnsignedNumber}, {'o', printOctal},
{'x', print_Hexadecimal_num},
{'X', print_hexadecimal_upper}, {'p', printPointer},
{'S', printNonPrintable},
{'r', reverse_print}, {'R', p_rot13string}, {'\0', NULL}
};
while (form_types[i].form != '\0')
{
if (format[*index] == form_types[i].form)
{
return (form_types[i].fuc(arg_list, output_buffer,
flags, width, precision, size));
}
i++;
}
if (format[*index] == '\0')
{
output_buffer[0] = '%';
output_buffer[1] = format[*index];
return (2);
}
unknown_len += _putchar('%');
unknown_len += _putchar(format[*index]);
return (unknown_len);
}
