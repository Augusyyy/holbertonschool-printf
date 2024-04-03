#include "main.h"

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_di(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	long int digit;
	int ret = 0, size = 0;
	char space = ' ', plus = '+';
	char str[100] = {0};
	char *q1;
	unsigned long int copy;

	(void) space;
	digit = va_arg(*args, long int);
	check1(&digit, length);
	if (flags[SPACE] == 1 && digit >= 0 && flags[PLUS] == 0)
		ret += _putchar(space);
	if (prec <= 0)
		check2(&digit, flags, &ret, &wid, prec);
	if (digit < 0)
		copy = -digit;
	else
		copy = digit;
	if (flags[ZERO] == 0 && (flags[PLUS] == 1 && digit >= 0))
		size++;
	if (!(digit == 0 && prec == 0))
	{
		q1 = citoa(copy, str, 10, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		if (flags[ZERO] == 0 && (flags[PLUS] == 1 && digit >= 0))
			ret += _putchar(plus);
		if (digit < 0 && flags[ZERO] == 0)
			ret += _putchar('-');
		prec = (prec == -1) ? size : prec;
		while (*q1 != '\0')
		{
			ret += _putchar(*q1);
			prec--;
			q1++;
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_b - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_b(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	unsigned int digit;
	char str[100] = {0};
	int size = 0;
	int ret = 0;
	char *q1;

	(void)length;
	digit = va_arg(*args, unsigned int);
	q1 = citoa(digit, str, 2, prec, &size);
	ret += print_string_width(flags, wid, size, size);
	prec = (prec == -1) ? size : prec;
	while (*q1 != '\0')
	{
		ret += _putchar(*q1);
		prec--;
		q1++;
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_u(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	unsigned long int digit;
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;

	digit = va_arg(*args, unsigned long int);
	if (length == LONG)
		digit = (unsigned long int) digit;
	else
		digit = (unsigned int) digit;
	if (length == SHORT)
		digit = (unsigned short) digit;
	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 10, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == -1) ? size : prec;
		while (*q1 != '\0')
		{
			ret += _putchar(*q1);
			prec--;
			q1++;
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: args list.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @length: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	unsigned long int digit;
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;

	digit = va_arg(*args, unsigned long int);
	if (length == LONG)
		digit = (unsigned long int) digit;
	else
		digit = (unsigned int) digit;
	if (length == SHORT)
		digit = (unsigned short) digit;
	if (flags[HASH] == 1 && digit != 0)
		ret += _putchar('0');
	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 8, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == -1) ? size : prec;
		while (*q1 != '\0')
		{
			ret += _putchar(*q1);
			prec--;
			q1++;
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

