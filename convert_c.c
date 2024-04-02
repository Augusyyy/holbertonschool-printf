#include "main.h"
/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec precision
 * @length length
 * Return: output length
 */
unsigned int convert_c(va_list *args, int *flags, int wid, int prec, unsigned char length)
{
	char c;
	unsigned int len = 0;

	(void) prec;
	(void) length;
	c = va_arg(*args, char );
	len += print_width(1, flags, wid);
	len += _putchar(c);
	len += print_neg_width(1, flags, wid);
	return (len);
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec precision
 * @length length
 * Return: output length
 */
unsigned int convert_p(va_list *args, int *flags, int wid, int prec, unsigned char length)
{
	unsigned long int address;
	char *null = "(nil)";
	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;

	(void) length;
	address = va_arg(*args, unsigned long int);
	if (address == '\0')
	{
		while (*null)
		{
			ret += _putchar(*null);
			null++;
		}
		return ret;
	}
	if (!(address == 0 && prec == 0))
	{
		q1 = chextoa(address, str, prec, &size);
		_putchar('0');
		_putchar('x');
		ret = 2;
		ret += print_string_width(flags, wid, prec, size+2);
		prec = (prec == -1) ? size : prec;
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
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec precision
 * @length length
 * Return: output length
 */
unsigned int convert_percent(va_list *args, int *flags, int wid, int prec, unsigned char length)
{
	char percent = '%';
	unsigned int ret = 0;

	(void) args;
	(void) prec;
	(void) length;
	ret += print_width(1, flags, wid);
	ret += _putchar(percent);
	ret += print_neg_width(1, flags, wid);
	return (ret);
}

