#include "main.h"

/**
 * calculatePrintWidth - Calculates the width value for printing
 * @formatString: The formatted string in which the arguments will be printed.
 * @currentIndex: The index of the current character in the format string.
 * @argList: The list of arguments.
 *
 * Return: The calculated print width.
 */

int calculatePrintWidth(const char *formatString,
		int *currentIndex, va_list argList)
{
	int printWidth = 0;

	 while (isCharacterDigit(formatString[*currentIndex]))
	{
		printWidth *= 10;
		printWidth += formatString[*currentIndex + 1] - '0';
		(*currentIndex)++;
	}

	if (formatString[*currentIndex + 1] == '*')
	{
		(*currentIndex)++;
		printWidth = va_arg(argList, int);
	}

	return (printWidth);
}




