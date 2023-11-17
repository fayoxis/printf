#include "main.h"

/**
* isCharacterPrintable - Checks if a character is printable.
* @ch: The character to be evaluated.
*
* Return: 1 if the character is printable, 0 otherwise.
*/
int isCharacterPrintable(char ch)
{
    return (ch >= 32 && ch < 127);
}
/**
* hexadecimal_code - Converts an ASCII code to its
* hexadecimal representation and appends it to the buffer.
* @buffer: An array of characters to which the
* hexadecimal code will be appended.
* @index: The index at which the appending will start.
* @ascii_code: The ASCII code to be converted and appended.
* Return: Always returns 3.
*/
int hexadecimal_code(char ascii_code, char buffer[], int index)
{
    const char hex_map[] = "0123456789ABCDEF";
    
    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[index++] = '\\';
    buffer[index++] = 'x';

    for (int i = 0; i < 2; i++)
    {
        buffer[index++] = hex_map[(ascii_code >> (4 - i * 4)) & 0xF];
    }

    return 3;
}
/**
* isCharacterDigit - Checks whether a character is a digit
* @ch: The character to be evaluated
*
* Return: 1 if the character is a digit, 0 otherwise
*/
int isCharacterDigit(char ch)
{
if (ch >= '0' && ch <= '9')
return (1);
return (0);
}
/**
* resize_number - Converts a number to the specified data size
* @number: Number to be converted
* @targetSize: Size indicating the data type to be converted to
*
* Return: Converted value of number
*/
long int resize_number(long int number, int targetSize)
{
if (targetSize == S_LONG)
return (number);
else if (targetSize == S_SHORT)
return ((short)number);

return ((int)number);
}
/**
* convert_number - Changes the data type of a number to the specified size
* @number: Number to be converted
* @size: Integer indicating the target data type size
*
* Return: Converted value of number with the specified data type
*/
long int convert_number(unsigned long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((unsigned short)number);

return ((unsigned int)number);
}
