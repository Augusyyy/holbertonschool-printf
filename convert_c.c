#include "main.h"

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @c: character
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * Return: output length
 */
unsigned int convert_c(char c,int *flags, int wid)
{
	unsigned int len = 0;
	
	len += print_width(1, flags, wid);
	len += _putchar(c);
	len += print_neg_width(1, flags, wid);
	return (len);
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @address: input digit
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * Return: output length
 */
unsigned int convert_p(unsigned long int address, int *flags,
                       int wid, int prec)
{
	char *null = "(nil)";
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;

	if (address == '\0')
		return (0);
	if (!(address == 0 && prec == 0))
	{
		q1 = chextoa(address, str, prec, &size);
		_putchar('0');
		_putchar('x');
		ret = 2;
		ret += print_string_width(flags, wid, prec, size+2);
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
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * Return: output length
 */
unsigned int convert_percent(int *flags, int wid)
{
	char percent = '%';
	unsigned int ret = 0;
	
	ret += print_width(1, flags, wid);
	ret += _putchar(percent);
	ret += print_neg_width(1, flags, wid);
	return (ret);
}

