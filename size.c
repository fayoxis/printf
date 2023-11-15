#include "main.h"

/**
 * determineSize - Calculates the size to cast the argument
 * @formatString: Formatted string in which to print the arguments
 * @currentIndex: Pointer to the current index in the format string
 *
 * Return: Size of the argument.
 */
int determineSize(const char *formatString, int *currentIndex)
{
	int size = 0;

	while (formatString[*currentIndex + 1] == 'l' ||
			formatString[*currentIndex + 1] == 'h')
	{
		(*currentIndex)++;

		if (formatString[*currentIndex] == 'l')
			size = S_LONG;
		else if (formatString[*currentIndex] == 'h')
			size = S_SHORT;
	}

	return (size);
}
