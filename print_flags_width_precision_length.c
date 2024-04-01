#include "main.h"

/**
 * print_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_width(unsigned int printed,
		int *flags, int wid)
{
	unsigned int ret = 0;
	char character = ' ';

	if (flags[ZERO] == 1)
	{
		character = '0';
	}
	if (flags[NEG] == 0)
	{
		for (wid -= printed; wid > 0;wid--)
		{
			ret += _putchar(character);
		}
	}
	return (ret);
}

/**
 * print_neg_width - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_neg_width(unsigned int printed,
		int *flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';
	
	if (flags[NEG] == 1)
	{
		for (wid -= printed; wid > 0; wid--)
		{
			ret += _putchar(width);
		}
	}
	return (ret);
}

/**
 * print_string_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: The size of the string.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_string_width(int *flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char character = ' ';
	
	if (flags[ZERO] == 1)
	{
		character = '0';
	}
	
	if (flags[NEG] == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
		{
			ret += _putchar(character);
		}
	}

	return (ret);
}

