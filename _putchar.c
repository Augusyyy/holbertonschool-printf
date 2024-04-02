#include "main.h"

/**
* _putchar - Entry point...
* Description: 'the program desc'
* Return: Always 0 (Success)
* @c: char parmameterr
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * check1 - check paramter
 * @digit:  digit
 * @length: length
 * Return: void
 */
void check1(long int *digit, unsigned char length)
{
	if (length == LONG)
		*digit = (long int) *digit;
	else
		*digit = (int) *digit;
	if (length == SHORT)
		*digit = (short) *digit;
}
/**
 * check2 - check paramter
 * @digit: digit
 * @flags: flags
 * @ret: ret
 * @wid: wid
 * @return: void
 */
void check2(long int *digit, int *flags, int *ret, int *wid)
{
	char pad, neg = '-', plus = '+';
	long int copy;
	int count = 0;

	if (*digit == LONG_MIN)
		count += 19;
	else
	{
		for (copy = (*digit < 0) ? -(*digit) : *digit; copy > 0; copy /= 10)
		{
			count++;
		}
	}
	count += (*digit == 0) ? 1 : 0;
	count += (*digit < 0) ? 1 : 0;
	count += (flags[PLUS] == 1 && *digit >= 0) ? 1 : 0;
	count += (flags[SPACE] == 1 && *digit >= 0) ? 1 : 0;
	if (flags[ZERO] == 1 && flags[PLUS] == 1 && *digit >= 0)
	{
		*ret += _putchar(plus);
	}
	if (flags[ZERO] == 1 && *digit < 0)
	{
		*ret = _putchar(neg);
		*digit = -(*digit);
	}
	pad = (flags[ZERO] == 1) ? '0' : ' ';
	for ((*wid) -= count; *wid > 0; (*wid)--)
	{
		*ret += _putchar(pad);
	}
}

