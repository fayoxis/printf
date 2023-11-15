#include "main.h"

/**
 * calculatePrecision - Calculates the precision value for printing
 * @formatString: Formatted string containing the print arguments
 * @currentIndex: Index of the current argument
 * @argList: List of arguments
 *
 * Return: The calculated precision value
 */
int calculatePrecision(const char *formatString,
		int *currentIndex, va_list argList)
{
	int currentIdx = *currentIndex + 1;
	int precision = -1;

	/* Check if precision is specified in the format string */
	if (formatString[currentIdx] != '.')
		return (precision);

	precision = 0;

	/* Parse the precision value */
	while (isCharacterDigit(formatString[currentIdx + 1]))
	{
		currentIdx++;
		precision *= 10;
		precision += formatString[currentIdx] - '0';
	}

	if (formatString[currentIdx + 1] == '*')
	{
		currentIdx += 2;
		precision = va_arg(argList, int);
	}

	*currentIndex = currentIdx;

	return (precision);
}
