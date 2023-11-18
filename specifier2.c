#include "main.h"

/**
 * printUnsignedNumber - Prints an unsigned number.
 * This function takes a list of arguments and prints the corresponding
 * unsigned number.It formats the number based on the provided flags, width,
 * precision, and size specifiers. The result is stored in the buffer array.
 * @argList: The list of arguments.
 * @outputBuffer: The buffer array to handle the print.
 * @flags: The active flags used for calculation.
 * @width: The width specifier.
 * @precision: The precision specification.
 * @sizeSpecifier: The size specifier.
 * Return: The number of characters printed.
 **/
int printUnsignedNumber(va_list argList, char outputBuffer[],
int flags, int width, int precision, int sizeSpecifier)
{
int bufferIndex = BUFF_SIZE - 2;
unsigned long int number = va_arg(argList, unsigned long int);
number = convert_number(number, sizeSpecifier);
if (number == 0)
outputBuffer[bufferIndex--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';
do {
outputBuffer[bufferIndex--] = (number % 10) + '0';
number /= 10;
} while (number > 0);
bufferIndex++;
return (writeUnsignedNumber(0, bufferIndex,
outputBuffer, flags, width, precision, sizeSpecifier));
}

/**
 * printOctal - Prints an unsigned number in octal notation
 * @argList: List of arguments
 * @outputBuffer: Buffer array used for printing
 * @calcFlags: Active flags for calculation
 * @widthSpec: Width specification
 * @precisionSpec: Precision specification
 * @sizeSpec: Size specifier
 * Return: Number of characters printed
 **/

int printOctal(va_list argList, char outputBuffer[],
int calcFlags, int widthSpec, int precisionSpec, int sizeSpec)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(argList, unsigned long int);
unsigned long int initNum = num;
UNUSED(widthSpec);
num = convert_number(num, sizeSpec);
if (num == 0)
outputBuffer[i--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';
do {
outputBuffer[i--] = (num % 8) + '0';
num /= 8;
} while (num > 0);
if (calcFlags & F_HASH && initNum != 0)
outputBuffer[i--] = '0';
i++;
return (writeUnsignedNumber(0, i, outputBuffer,
calcFlags, widthSpec, precisionSpec, sizeSpec));
}

/**
 * print_Hexadecimal_num - Outputs an unsigned
 * number using hexadecimal notation
 * @types: List of arguments containing the number to be printed
 * @buffer: Array used as a buffer for printing
 * @flags: Active flag calculation for formatting
 * @width: Width specification for formatting
 * @precision: Precision specification for formatting
 * @size: Size specifier for formatting
 * Returns: The count of characters printed
 **/
int print_Hexadecimal_num(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (printed_Hexadecimal(types, "0123456789abcdef",
buffer, flags, 'x', width, precision, size));
}

/**
 * print_hexadecimal_upper - Prints an unsigned number
 * in uppercase hexadecimal notation.
 * @types: List of arguments.
 * @buffer: Buffer array used for printing.
 * @flags: Calculation of active flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: The number of characters printed.
 **/

int print_hexadecimal_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (printed_Hexadecimal(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
 * print_Hexadecimal - Converts and prints a hexadecimal
 * number in lowercase or uppercase
 * @args: List of arguments
 * @mapping: Array of characters used for mapping the number
 * @outputBuffer: Buffer array for storing the printed output
 * @flags: Calculation of active flags
 * @flagChar: Character for active flag calculation
 * @width: Width value
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 **/
int printed_Hexadecimal(va_list args, char mapping[], char outputBuffer[],
int flags, char flagChar, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int number = va_arg(args, unsigned long int);
unsigned long int originalNumber = number;
UNUSED(width);
number = convert_number(number, size);
if (number == 0)
outputBuffer[i--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';
do {
outputBuffer[i--] = mapping[number % 16];
number /= 16;
} while (number > 0);
if (flags & F_HASH && originalNumber != 0)
{
outputBuffer[i--] = flagChar;
outputBuffer[i--] = '0';
}
i++;
return (writeUnsignedNumber(0, i, outputBuffer,
flags, width, precision, size));
}
