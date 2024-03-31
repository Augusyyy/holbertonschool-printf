#include "main.h"

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(long int digit, int *flags,
		int wid, int prec, unsigned char len)
{
	long int copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';
	char str[100] = {0};
	int size = 0;
	char *q1;
	
	if (len == LONG)
		digit = (long int) digit;
	else
		digit = (int) digit;
	if (len == SHORT)
		digit = (short)digit;
	
	if (flags[SPACE] == 1 && digit >= 0){
		ret += _putchar(space);
	}
	
	if (prec <= 0 && flags[NEG] == 0) /* Handle width  */
	{
		if (digit == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (digit < 0) ? -digit : digit; copy > 0; copy /= 10)
			{
				count++;
			}
		}
		count += (digit == 0) ? 1 : 0;
		count += (digit < 0) ? 1 : 0;
		count += (flags[PLUS] == 1 && digit >= 0) ? 1 : 0;
		count += (flags[SPACE] == 1 && digit >= 0) ? 1 : 0;
		
		if (flags[ZERO] == 1 && flags[PLUS] == 1 && digit >= 0)
		{
			ret += _putchar(plus);
		}
		if (flags[ZERO] == 1 && digit < 0)
		{
			ret = _putchar(neg);
			digit = -digit;
		}

		pad = (flags[ZERO] == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
		{
			ret += _putchar(pad);
		}
	}
	
	if (flags[ZERO] == 0 && (flags[PLUS] == 1 && digit >= 0))
	{
		size++;
	}
	
	if (!(digit == 0 && prec == 0))
	{
		q1 = citoa(digit,str,10, prec,&size);
		ret += print_string_width(flags, wid, size, size);
		if (flags[ZERO] == 0 && (flags[PLUS] == 1 && digit >= 0))
		{
			ret += _putchar(plus);
		}
		prec = (prec == 0) ? size : prec;
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
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_b(unsigned int digit, int *flags,
		int wid, int prec, unsigned char len)
{
	char str[100] = {0};
	int size = 0;
	int ret = 0;
	char *q1;
	
	(void)len;
	
	q1 = citoa(digit, str, 2, prec, &size);
	ret += print_string_width(flags, wid, size, size);
	prec = (prec == 0) ? size : prec;
	while (*q1 != '\0')
	{
		ret += _putchar(*q1);
		prec--;
		q1++;
	}
	ret += print_neg_width(ret, flags, wid);
	return len;
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_u(unsigned long int digit, int *flags,
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
		q1 = cuitoa(digit, str, 10, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		prec = (prec == 0) ? size : prec;
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
 * @digit: input digit.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(unsigned long int digit, int * flags,
		int wid, int prec, unsigned char len)
{
       	unsigned int ret = 0;
	char str[100] = {0};
	int size = 0;
	char *q1;
	
	if (len == LONG)
		digit = (unsigned long int)digit;
	else
		digit = (unsigned int)digit;
	
	if (len == SHORT)
		digit = (unsigned short)digit;

	if (!(digit == 0 && prec == 0))
	{
		q1 = cuitoa(digit, str, 8, prec, &size);
		ret += print_string_width(flags, wid, size, size);
		
		prec = (prec == 0) ? size : prec;
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


