#include "main.h"
 
/**
 * calculate_flags - this is Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @k: Index parameter
 * Return: Flags:
 */

int calculate_flags(const char *format, int *k) {
    int flags = 0;

    while (format[*k] == '-') {
        flags |= 1; 
        (*k)++;
    }

    return flags;
}
