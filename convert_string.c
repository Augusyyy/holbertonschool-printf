#include "main.h"

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @str: input str
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * Return: Output length
 */
unsigned int convert_s(char *str,int *flags, int wid,
		int prec)
{
	int size;
	unsigned int ret = 0;
	char * nullstr = "(null)";
	
	if (str == NULL)
	{
		while (*nullstr)
		{
			ret += _putchar(*nullstr);
			nullstr++;
		}
		return ret;
	}
	
	for (size = 0; *(str + size);)
		size++;
	
	ret += print_string_width(flags, wid, prec, size);
	
	prec = (prec == -1) ? size : prec;
	
	while (*str != '\0' && prec > 0)
	{
		ret += _putchar(*str);
		prec--;
		str++;
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @str: input str
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * Return: Output length
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(char *str, int *flags,
		int wid, int prec)
{
	char zero = '0';
	int size, index;
	unsigned int ret = 0;
	char temp[10] = {0};
	char *q1;
	
	if (str == NULL)
		return (0);
	
	for (size = 0; str[size];)
		size++;
	
	ret += print_string_width(flags, wid, prec, size);
	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _putchar('\\');
			ret += _putchar('x');
			if (*(str + index) < 16)
			{
				ret += _putchar(zero);
			}
			
			q1 = chextoa(*(str + index), temp, prec, &size);
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
				q1++;
			}
			continue;
		}
		ret += _putchar(*(str + index));
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @str: input str
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(char *str, int *flags,
		int wid, int prec, unsigned char len)
{
	int size, end, i;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	if (str == NULL)
	{
		return (0);
	}
	for (size = 0; *(str + size);)
		size++;
	ret += print_string_width(flags, wid, prec, size);
	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		ret += _putchar(*(str + end));
		end--;
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @str: input str
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(char *str, int *flags,
		int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, size;
	unsigned int ret = 0;
	
	(void)flags;
	(void)len;
	
	if (str == NULL)
	{
		return (0);
	}

	for (size = 0; *(str + size);)
		size++;
	
	ret += print_string_width(flags, wid, prec, size);
	prec = (prec == -1) ? size : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ret += _putchar(*(rot13 + j));
				break;
			}
		}
		if (j == 52)
		{
			ret += _putchar(*(str + i));
		}
	}
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

