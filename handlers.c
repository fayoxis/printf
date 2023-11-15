#include "main.h"

/**
 * printed_character - Prints a single character
 * @ch: The character to be printed
 * @buffer: Buffer array used for printing
 * @flags: Flags indicating active calculations
 * @width: Width specifier for formatting
 * @precision: Precision specifier for formatting
 * @size: Size specifier for formatting
 * Return: Number of characters printed
 */
int printed_character(char ch, char buffer[], int flags, int width,
int precision, int size)
{
int i, j;
char padding = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padding = '0';
buffer[0] = ch;
buffer[1] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 2; i <= width && i < BUFF_SIZE; i++)
buffer[BUFF_SIZE - i] = padding;
i--;
}
if (flags & F_MINUS)
{
for (j = 0; j < i; j++)
write(1, &buffer[j], 1);
return (write(1, &buffer[BUFF_SIZE - i], width - 1) + i);
}
else
{
for (j = BUFF_SIZE - i; j < BUFF_SIZE; j++)
write(1, &buffer[j], 1);
return (write(1, &buffer[0], 1) + i - 1);
}
}

/**
 * writeUnsignedNumber - Function for writing an unsigned number
 * @isNegative: Flag indicating if the number is negative
 * @startIndex: Index at which the number starts in the buffer
 * @buffer: Array of characters
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters written.
 */
int writeUnsignedNumber(int isNegative, int startIndex, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - startIndex - 1;
int i = 0;
char paddingChar = ' ';
UNUSED(isNegative);
UNUSED(size);
if (precision == 0 && startIndex == BUFF_SIZE - 2
&& buffer[startIndex] == '0')
return (0);
if (precision > 0 && precision < length)
paddingChar = ' ';
while (precision > length)
{
buffer[--startIndex] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
paddingChar = '0';
if (width > length)
{
i = width - length;
for (; i < width; i++)
buffer[i] = paddingChar;
buffer[i] = '\0';
if (flags & F_MINUS)
{
int writtenChars = write(1, &buffer[startIndex], length);
writtenChars += write(1, &buffer[0], i);
return (writtenChars);
}
else
{
int writtenChars = write(1, &buffer[0], i);
writtenChars += write(1, &buffer[startIndex], length);
return (writtenChars);
}
}
return (write(1, &buffer[startIndex], length));
}

/**
 * writeMemoryAddress - Writes a memory address to a character buffer
 * @buffer: Array of characters representing the buffer
 * @startIndex: Index at which the number starts in the buffer
 * @numberLength: Length of the number
 * @width: Width specifier
 * @flags: Flags specifier
 * @paddingChar: Character representing the padding
 * @extraChar: Character representing an extra character
 * @paddingStartIndex: Index at which the padding should start
 *
 * Return: Number of characters written.
 */
int writeMemoryAddress(char buffer[], int startIndex, int numberLength,
int width, int flags, char paddingChar, char extraChar, int paddingStartIndex)
{
int i;
if (width > numberLength)
{
for (i = 3; i < width - numberLength + 3; i++)
buffer[i] = paddingChar;
buffer[i] = '\0';
if (!(flags & F_MINUS) && paddingChar == '0')
{
if (extraChar)
buffer[--paddingStartIndex] = extraChar;
buffer[1] = '0';
buffer[2] = 'x';
return ((write(1, &buffer[paddingStartIndex], i - paddingStartIndex) +
write(1, &buffer[startIndex], numberLength - (1 - paddingStartIndex) - 2)));
}
buffer[--startIndex] = 'x';
buffer[--startIndex] = '0';
if (extraChar)
buffer[--startIndex] = extraChar;
if (flags & F_MINUS)
return ((write(1, &buffer[startIndex], numberLength) +
write(1, &buffer[3], i - 3)));
return ((write(1, &buffer[3], i - 3) +
write(1, &buffer[startIndex], numberLength)));
}
buffer[--startIndex] = 'x';
buffer[--startIndex] = '0';
if (extraChar)
buffer[--startIndex] = extraChar;
return ((write(1, &buffer[startIndex], BUFF_SIZE - startIndex - 1)));
}
