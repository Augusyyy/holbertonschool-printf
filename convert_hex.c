#include "main.h"
/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_x(va_list *args, int *flags,
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
		digit = (unsigned short)digit;
	if (flags[HASH] == 1 && digit != 0)
	{
		ret += _putchar('0');
		ret += _putchar('x');
	}
	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 16, prec, &size);
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
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_X(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	unsigned long int digit;
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;

	digit = va_arg(*args, unsigned long int);
	if (length == LONG)
		digit = (unsigned long)digit;
	else
		digit = (unsigned int)digit;
	if (length == SHORT)
		digit = (unsigned short)digit;
	if (flags[HASH] == 1 && digit != 0)
	{
		ret += _putchar('0');
		ret += _putchar('x');
	}
	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 16, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == -1) ? size : prec;
		while (*q1 != '\0')
		{
			if (*q1 >= 97 && *q1 <= 102)
				ret += _putchar(*q1 - 32);
			else
				ret += _putchar(*q1);
			prec--;
			q1++;
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

