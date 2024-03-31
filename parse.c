#include "main.h"

/**
 * parse_flags - Matches flags with corresponding values.
 * @flag: A pointer to a potential string of flags.
 * @ret: parsed result
 * Return: flags length
 */
int parse_flags(const char *flag, int * ret)
{
	int i, j, len = 0;
	char flags[5] = {'+',' ','#','0','-'};
	
	for (i = 0; i < 5; i++) 
	{
		ret[i] = 0;
	}
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (flag[i] == flags[j])
			{
				ret[j] = 1;
				len++;
				break;
			}
		}
		if (j == 5)
		{
			break;
		}
	}
	return (len);
}

/**
 * parse_length - Matches length modifiers with their corresponding value.
 * @modifier: A pointer to a potential length modifier.
 * @length: parsed result
 * Return: flags length
 */
int parse_length(const char *modifier, int *length)
{
	int len = 0;
	
	if (*modifier == 'h')
	{
		len++;
		*length =  (SHORT);
	}
	else if (*modifier == 'l')
	{
		len++;
		*length =  (LONG);
	}
	return (len);
}

/**
 * parse_width - Matches a width modifier with its corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential width modifier.
 * @width: parsed result
 * Return: flags length
 */
int parse_width(va_list args, const char *modifier, int *width)
{
    int len = 0;
    *width = 0;
    while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
    {
        len++;
        if (*modifier == '*')
        {
            *width = va_arg(args, int);
            if (*width <= 0)
                return (0);
            return (*width);
        }

        *width *= 10;
        *width += (*modifier - '0');
        modifier++;
    }

    return (len);
}

/**
 * parse_precision - Matches a precision modifier with
 *                    its corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential precision modifier.
 * @precision: parsed result
 *
 * Return: flags length
 */
int parse_precision(va_list args, const char *modifier, int *precision)
{
    int len = 0;
    *precision = 0;
    if (*modifier != '.')
        return (0);

    modifier++;
    len++;

    if ((*modifier <= '0' || *modifier > '9') &&
        *modifier != '*')
    {
        if (*modifier == '0')
            len++;
        return (0);
    }

    while ((*modifier >= '0' && *modifier <= '9') ||
           (*modifier == '*'))
    {
        len++;
        if (*modifier == '*')
        {
            *precision = va_arg(args, int);
            if (*precision <= 0)
                return (0);
            return (*precision);
        }

        *precision *= 10;
        *precision += (*modifier - '0');
        modifier++;
    }
    return (len);
}


/**
 * parse_specifiers - Matches a conversion specifier with
 *                     a corresponding conversion function.
 * @specifier: A pointer to a potential conversion specifier.
 * Return: If a conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
char parse_specifiers(const char *specifier)
{
    int i;
    char specifiers[14] = {'c','s','d','i',
                           '%','b','u','o',
                           'x','X','S','p',
                           'r','R'};

    for (i = 0; i < 14; i++)
    {
        if (specifiers[i] == *specifier)
            return specifiers[i];
    }

    return (0);
}

