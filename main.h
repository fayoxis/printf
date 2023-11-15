#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define F_MINUS  1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/*
 * @struct form
 * form - format operation
 * Struct representing a format operation.
 * Description - This struct holds information about a format operation,
 * including the format string and the associated function.
 * @form: The format string.
 * @fuc: The associated function.
 */

struct form
{
	char form;
	int (*fuc)(va_list, char[], int, int, int, int);
};

/**
 * @typedef form_t
 * Typedef for struct form, representing a format operation.
 * Description - This typedef defines a shorthand alias for the struct fmt.
 * The struct holds information about a format operation,
 * including the format string and the associated function.
 * @form: The format string.
 * @form_t: The associated function.
 */

typedef struct form form_t;
void print_buffer(char buffer[], int *buff_ind);
int _putchar(char c);
int _printf(const char *format, ...);
int print_character(va_list args, char buffer[],
int flags, int width, int precision, int size);
int printString(va_list argList, char buffer[],
int flags, int width, int precision, int size);

int printPercent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int printInteger(va_list types, char buffer[],
int flags, int width, int precision, int size);
int printBinary(va_list arguments, char buffer[],
int flags, int width, int precision, int size);

int printUnsignedNumber(va_list argList, char outputBuffer[],
int flags, int width, int precision, int sizeSpecifier);
int printOctal(va_list argList, char outputBuffer[],
int calcFlags, int widthSpec, int precisionSpec, int sizeSpec);
int printed_Hexadecimal(va_list args, char mapping[], char outputBuffer[],
int flags, char flagChar, int width, int precision, int size);
int print_hexadecimal_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_Hexadecimal_num(va_list types, char buffer[], int flags,
int width, int precision, int size);


int printPointer(va_list args, char buffer[],
int flags, int width, int precision, int size);
int printNonPrintable(va_list args, char buffer[],
int flags, int width, int precision, int size);
int reverse_print(va_list args, char buffer[],
int flags, int width, int precision, int size);
int p_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*flags */
int calculate_flags(const char *format, int *k);
/*precision */
int calculatePrecision(const char *formatString,
int *currentIndex, va_list argList);
/*size */
int determineSize(const char *formatString, int *currentIndex);
/* calculateWidth */
int calculatePrintWidth(const char *formatString,
int *currentIndex, va_list argList);
/* print_argument function */
int print_argument(const char *format, int *index, va_list arg_list,
char output_buffer[], int flags, int width, int precision, int size);
/* U_code*/
int isCharacterPrintable(char ch);
int hexadecimal_code(char ascii_code, char buffer[], int index);
int isCharacterDigit(char ch);
long int resize_number(long int number, int targetSize);
long int convert_number(unsigned long int number, int size);
/* handlers */
int printed_character(char ch, char buffer[],
int flags, int width, int precision, int size);
int printFormattedNumber(int isNegative, int index, char buffer[],
int flags, int width, int precision, int size);
int print_formatted_number(int start_index, char buffer[],
int flags, int width, int precision, int num_length,
char padding_char, char extra_char);
int writeUnsignedNumber(int isNegative, int startIndex,
char buffer[], int flags, int width, int precision, int size);
int writeMemoryAddress(char buffer[], int startIndex, int numberLength,
int width, int flags, char paddingChar, char extraChar, int paddingStartIndex);

#endif /* MAIN_H */
