#include "main.h"

/**
 * print_character - Prints a single character
 * @args: Variable arguments list
 * @buffer: Buffer array for print handling
 * @flags: Flag calculations
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * This function prints a single character. It takes a variable arguments list, 
 * a buffer array for print handling, flag calculations, width and precision 
 * specifications, and a size specifier. The character to be printed is retrieved 
 * from the variable arguments list. The function returns the number of characters 
 * printed.
 * Return: Number of characters printed
 */

int print_character(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(args, int);
return (printed_character(c, buffer, flags, width, precision, size));
}

/**
 * printString - Prints a string
 * @argList: A va_list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Integer value indicating active flags
 * @width: Width of the string
 * @precision: Precision specification
 * @size: Size specifier
 * This function prints a string based on the provided
 * arguments. It takes a va_list of arguments,
 * buffer array for printing, flags to calculate active
 * flags, width and precision for formatting,
 * and size for size specification. The function
 * returns the number of characters printed.
 */

int printString(va_list argList, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(argList, char *);
UNUSED(size);

if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
for (length = 0; str[length] != '\0'; length++)
;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
for (i = 0; i < length; i++)
buffer[i] = str[i];
for (i = length; i < width; i++)
buffer[i] = ' ';
return (width);
}
else
{
for (i = 0; i < width - length; i++)
buffer[i] = ' ';
for (int j = 0; j < length; i++, j++)
buffer[i] = str[j];
return (width);
}
}
else
{
for (i = 0; i < length; i++)
buffer[i] = str[i];
return (length);
}
}


/**
 * printPercent - This function prints a percent sign.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags 
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The number of characters printed.
 */

int printPercent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
 * printInteger - Prints an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Calculation of active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */

int printInteger(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int isNegative = 0;
long int number = va_arg(types, long int);
unsigned long int num;
number = resize_number(number, size);
if (number < 0)
{
num = (unsigned long int)(-number);
isNegative = 1;
}
else
{
num = (unsigned long int)number;
}
if (precision == 0 && num == 0)
{
buffer[i--] = '\0';
}
else
{
do {
buffer[i--] = (num % 10) + '0';
num /= 10;
}
while (num > 0);
}
i++;
return (printFormattedNumber(isNegative, i, buffer,
flags, width, precision, size));
}

/*
int printFormatNumber(int isNegative, int i, char buffer[],
int flags, int width, int precision, int size)
{
int len;
int j;
int printed_chars = 0;
if (isNegative)
{
buffer[i--] = '-';
}
len = BUFF_SIZE - 2 - i;
if (precision > len - isNegative)
{
for (j = len - isNegative; j < precision; j++)
{
buffer[i--] = '0';
}
}

if (!(flags & F_MINUS))
{
while (width > len)
{
buffer[i--] = (flags & F_ZERO) ? '0' : ' ';
width--;
}
}
for (j = i + 1; j < BUFF_SIZE - 1; j++)
{
write(1, &buffer[j], 1);
printed_chars++;
}
if (flags & F_MINUS)
{
while (width > len)
{
write(1, " ", 1);
width--;
printed_chars++;
}
}
UNUSED(size);
return (printed_chars);
}

*/
