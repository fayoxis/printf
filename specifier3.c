#include "main.h"
/**
 * printPointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags for calculation
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 **/
int printPointer(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
char extraChar = 0, paddingChar = ' ';
int index = BUFF_SIZE - 2, length = 2;
int paddingStart = 1; /* length=2 for '0x' */
unsigned long numAddrs;
char mapTo[] = "0123456789abcdef";
void *address = va_arg(args, void *);

UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (address == NULL)
return ((write(1, "(nil)", 5)));
buffer[BUFF_SIZE - 1] = '\0';
numAddrs = (unsigned long)address;
do {
buffer[index--] = mapTo[numAddrs % 16];
numAddrs /= 16;
length++;
} while (numAddrs > 0);
if ((flags & F_ZERO) && !(flags & F_MINUS))
paddingChar = '0';
if (flags & F_PLUS)
extraChar = '+', length++;
else if (flags & F_SPACE)
extraChar = ' ', length++;
index++;
return ((writeMemoryAddress(buffer, index, length,
width, flags, paddingChar,
extraChar, paddingStart)));
}
/**
 * printNonPrintable - This function prints the
 * hexadecimal representation of non-printable characters.
 * @args: The list of arguments.
 * @buffer: The buffer array used for handling the printing.
 * @flags: The calculated active flags.
 * @width: The width specification.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: The number of characters printed.
 **/
int printNonPrintable(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str = va_arg(args, char *);
UNUSED(width);
UNUSED(flags);
UNUSED(buffer);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
if (isCharacterPrintable(str[i]))
buffer[i + offset] = str[i];
else
offset += hexadecimal_code(str[i], buffer, i + offset);
i++;
if (i + offset >= BUFF_SIZE - 1)
{
write(1, buffer, i + offset);
offset = 0;
i = 0;
}
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
}
/**
 * reverse_print - Prints a string in reverse order.
 * @args: List of arguments
 * @buffer: Buffer array used for print handling
 * @flags: Calculation of active flags (not used in this function)
 * @width: Width specification (not used in this function)
 * @precision: Precision specification (not used in this function)
 * @size: Size specifier (not used in this function)
 * Return: Number of characters printed
 **/
int reverse_print(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(args, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
if (precision == -1 && str[0] == '%' && str[1] == 'r')
{
for (i = count - 1; i >= 0; i--)
{
char z = buffer[i];
_putchar(z);
}
return (count);
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str[i];
_putchar(z);
count++;
}
return (count);
}
/**
 * p_rot13string - Prints a string using the ROT13 cipher.
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags for calculation
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *Return: Number of characters printed.
 */
int p_rot13string(va_list args, char buffer[],
int flags, int width, int precision, int size)
{
\char *str;
unsigned int i, j, k;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
UNUSED(buffer);
str = va_arg(args, char *);
if (str == NULL)
str = "(NULL)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
char x = out[j];
for (k = 0; k < 1; k++)
{
write(1, &x, 1); /* Write character to output */
count++;
}
break;
}
}
if (!in[j])
{
char x = str[i];
for (k = 0; k < 1; k++)
{
write(1, &x, 1); /* Write character to output */
count++;
}
}
}
return (count);
}
