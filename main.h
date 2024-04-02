#ifndef HOLBERTON_PRINTF_MAIN_H
#define HOLBERTON_PRINTF_MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

#define PLUS 0
#define SPACE 1
#define HASH 2
#define ZERO 3
#define NEG 4


/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list *, int *,
			int, int, unsigned char);
} converter_t;


int _printf(const char *format, ...);
int _putchar(char c);

void check1(long int *digit, unsigned char length);
void check2(long int *digit, int *flags, int *ret, int *wid);

char *citoa(long int num, char *str, int base, int prec, int *size);
char *cuitoa(unsigned int num, char *str, int base, int prec, int *size);
char *chextoa(long int  addr, char *str, int prec, int *size);

void reverse(char str[], int length);

int parse_flags(const char *flag, int *ret);
int parse_length(const char *modifier, int *length);
int parse_width(va_list *args, const char *modifier, int *width);
int parse_precision(va_list *args, const char *modifier, int *precision);
unsigned int (*parse_specifiers(const char *specifier))(va_list *,
		int *, int, int, unsigned char);

unsigned int convert_c(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_s(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_di(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_b(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_u(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_o(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_X(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_x(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_percent(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_p(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_R(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_r(va_list *args, int *flags,
		int wid, int prec, unsigned char length);
unsigned int convert_S(va_list *args, int *flags,
		int wid, int prec, unsigned char length);

unsigned int print_width(unsigned int printed,
		int *flags, int wid);
unsigned int print_neg_width(unsigned int printed,
		int *flags, int wid);
unsigned int print_string_width(int *flags, int wid,
		int prec, int size);

void free_buffer(buffer_t *output);
buffer_t *init_buffer(void);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);

#endif

