#include "main.h"
/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(unsigned long int digit, int *flags,
		int wid, int prec, unsigned char len)
{
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;
	
	if (len == LONG)
		digit = (unsigned long int) digit;
	else
		digit = (unsigned int) digit;
	
	if (len == SHORT)
		digit = (unsigned short)digit;

	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 16, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == 0) ? size : prec;
		while (*q1 != '\0')
		{
			ret += _putchar(*q1);
			prec--;
			q1++;
		}
	}
	ret += print_neg_width( ret, flags, wid);
	return (ret);
}

/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_X(unsigned long int digit, int *flags,
		int wid, int prec, unsigned char len)
{
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;
	
	if (len == LONG)
		digit = (unsigned long)digit;
	else
		digit = (unsigned int)digit;
	if (len == SHORT)
		digit = (unsigned short)digit;
	
	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 16, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == 0) ? size : prec;
		while (*q1 != '\0')
		{
			if (*q1 >= 97 && *q1 <= 102)
			{
				ret += _putchar(*q1 - 32);
			}
			else
			{
				ret += _putchar(*q1);
			}
			prec--;
			q1++;
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

