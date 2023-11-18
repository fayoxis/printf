#include "main.h"

/**
* printFormattedNumber - Prints a formatted number
* @isNegative: Indicates whether the number is negative
* @index: Index position in the buffer array
* @buffer: Buffer array for printing
* @flags: Active flags for formatting
* @width: Width specifier
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed
**/
int printFormattedNumber(int isNegative, int index, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - index - 1;
char padd = ' ', extra_ch = 0;
int result, i = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (isNegative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
while (buffer[i] != '\0')
{
i++;
}
result = print_formatted_number(index, buffer, flags, width,
precision, length, padd, extra_ch);
return (result);
}

/**
 * print_formatted_number - Prints a formatted number using a buffer
 * @start_index: Index at which the number starts in the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision specifier
 * @num_length: Number length
 * @padding_char: Padding character
 * @extra_char: Extra character
 * Prints a formatted number using the provided buffer and parameters.
 * Returns: The number of characters printed.
 **/
int print_formatted_number(int start_index, char buffer[], int flags,
int width, int precision, int num_length,
char padding_char, char extra_char) {
int i, padding_start = 1;
int printed_chars = 0;
int padding_count = width - num_length;
char *padding_buffer = (char *)malloc(padding_count + 1);
if (precision == 0 && start_index == BUFF_SIZE - 2 &&
buffer[start_index] == '0') {
if (width == 0)
return (0);
buffer[start_index] = padding_char = ' ';
}
if (precision > 0 && precision < num_length)
padding_char = ' ';
while (precision > num_length)
buffer[--start_index] = '0', num_length++;
if (extra_char != 0)
num_length++;
if (width > num_length)
{
for (i = 0; i < padding_count; i++)
padding_buffer[i] = padding_char;
padding_buffer[i] = '\0';
if (flags & F_MINUS && padding_char == ' ')
{
if (extra_char)
buffer[--start_index] = extra_char, num_length++;
printed_chars += write(1, &buffer[start_index], num_length);
printed_chars += write(1, padding_buffer, padding_count);
}
else
{
if (extra_char)
{
if (padding_char == '0')
buffer[--padding_start] = extra_char;
else
buffer[--start_index] = extra_char, num_length++;
}
printed_chars += write(1, padding_buffer, padding_count);
printed_chars += write(1, &buffer[start_index], num_length);
}
return (printed_chars);
}
if (extra_char)
buffer[--start_index] = extra_char;
printed_chars = write(1, &buffer[start_index], num_length);
return (printed_chars);
}

/**
 * printBinary - Prints an unsigned number in binary format
 *
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */

int printBinary(va_list arguments, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int number, divisor, i;
unsigned int binaryArray[32];
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	number = va_arg(arguments, unsigned int);
	divisor = 2147483648; /* (2 ^ 31) */
	binaryArray[0] = number / divisor;

	for (i = 1; i < 32; i++)
	{
		divisor /= 2;
		binaryArray[i] = (number / divisor) % 2;
	}

	i = 0;
	while (i < 32 && binaryArray[i] == 0)
	{
		i++;
	}
	for (; i < 32; i++)
	{
		char binaryChar = '0' + binaryArray[i];

		write(1, &binaryChar, 1);
		count++;
	}
	return (count);
}

