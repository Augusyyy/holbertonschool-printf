#include "main.h"

/**
 * citoa  -  Converts int num to string
 * @num: input int type integer number
 * @str: a character array.
 * @base: base format example 2,8,10,16
 * @prec: precision
 * @size: size of str
 * Return: a character array.
 */
char *citoa(long int num, char *str, int base, int prec, int *size)
{
	int i = 0;
	bool isNegative = false;
	int rem;
	unsigned long int copy;

	if (num == 0)
	{
		str[i++] = '0';
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		copy = -num;
	}
	else
	{
		copy = num;
	}
	while (copy != 0)
	{
		rem = copy % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		copy = copy / base;
	}
	while (prec > i)
	{
		str[i++] = '0';
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	*size += i;
	return (str);
}

/**
 * cuitoa  -  Converts unsigned int num to string
 * @num: input unsigned int type integer number
 * @str: a character array.
 * @base: base format example 2,8,10,16
 * @prec: precision
 * @size: size of str
 * Return: a character array.
 */
char *cuitoa(unsigned long int num, char *str, int base, int prec, int *size)
{
	int i = 0;
	bool isNegative = false;
	int rem = 0;

	(void)prec;
	if (num == 0)
	{
		str[i++] = '0';
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	while (prec > i)
	{
		str[i++] = '0';
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	*size += i;
	reverse(str, i);
	return (str);
}

/**
 * chextoa -  Converts long int num to address
 * @addr: input long int type integer number
 * @str: a character array.
 * @prec: precision.
 * @size: str size.
 * Return: a character array.
 */
char *chextoa(unsigned long int addr, char *str, int prec, int *size)
{
	int i = 0, rem = 0;

	(void) prec;
	if (!addr)
	{
		str[i++] = '0';
		str[i] = '\0';
		(*size)++;
		return (str);
	}
	while (addr)
	{
		rem = addr % 16;
		if (rem < 10)
			str[i] = '0' + rem;
		else
			str[i] = 'a' + (rem - 10);
		addr /= 16;
		i++;
	}
	str[i] = '\0';
	*size += i;
	reverse(str, i);
	return (str);
}

/**
 * reverse -  reverse string
 * @str: a character array.
 * @length: length.
 * Return: a character array.
 */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

