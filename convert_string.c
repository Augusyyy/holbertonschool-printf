#include "main.h"

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_s(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	char *str;
	int size;
	unsigned int ret = 0;
	char *nullstr = "(null)";

	(void) length;
	str = va_arg(*args, char *);
	if (str == NULL)
	{
		while (*nullstr)
		{
			ret += _putchar(*nullstr);
			nullstr++;
		}
		return (ret);
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
 * sub_convert_S - sub_convert_S
 * @ret: ret
 * @str: str
 * @prec: prec
 * @size: size
 * Return: void
 */
void sub_convert_S(unsigned int *ret, char *str, int prec, int *size)
{
	char zero = '0';
	char temp[1024] = {0};
	int index;
	char *q1;

	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			*ret += _putchar('\\');
			*ret += _putchar('x');
			if (*(str + index) < 16)
			{
				*ret += _putchar(zero);
			}
			q1 = chextoa(*(str + index), temp, prec, size);
			while (*q1 != '\0')
			{
				if (*q1 >= 97 && *q1 <= 102)
				{
					*ret += _putchar(*q1 - 32);
				}
				else
				{
					*ret += _putchar(*q1);
				}
				q1++;
			}
			continue;
		}
		*ret += _putchar(*(str + index));
	}
}
/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_S(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	char *str;
	int size;
	unsigned int ret = 0;

	(void) length;
	str = va_arg(*args, char *);
	if (str == NULL)
		return (0);
	for (size = 0; str[size];)
		size++;
	ret += print_string_width(flags, wid, prec, size);
	prec = (prec == -1) ? size : prec;
	sub_convert_S(&ret, str, prec, &size);
	ret += print_neg_width(ret, flags, wid);
	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_r(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	char *str;
	int size, end, i;
	unsigned int ret = 0;

	(void)flags;
	(void)length;
	str = va_arg(*args, char *);
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
 * @args: va_list
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: precision
 * @length: length
 * Return: output length
 */
unsigned int convert_R(va_list *args, int *flags,
		int wid, int prec, unsigned char length)
{
	char *str;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, size;
	unsigned int ret = 0;

	(void)flags;
	(void)length;
	str = va_arg(*args, char *);
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

