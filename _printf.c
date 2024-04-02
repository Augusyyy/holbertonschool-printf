#include "main.h"

/**
 * parse - parse parameter
 * @p: data string
 * @flags: flags
 * @wid: wid
 * @precision: precision
 * @length: length
 * @args: args
 * Return: The number of characters printed.
 */
int parse(const char *p, int *flags, int *wid,
		int *precision, int *length, va_list *args)
{
	int offset = 0;
	int count = 0;

	offset = parse_flags(p, flags);
	p += offset;
	count += offset;
	offset = parse_width(args, p, wid);
	p += offset;
	count += offset;
	offset = parse_precision(args, p, precision);
	p += offset;
	count += offset;
	offset = parse_length(p, length);
	count += offset;
	return (count);
}
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *p = format;
	int count = 0, offset = 0, wid = 0, precision = -1, length = 0;
	int flags[5] = {0};
	unsigned int (*f)(va_list *, int *, int, int, unsigned char);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			offset = parse(p, flags, &wid, &precision, &length, &args);
			p += offset;
			f = parse_specifiers(p);
			if (f != NULL)
			{
				count += f(&args, flags, wid, precision, length);
			}
			else
			{
				count += _putchar(*(p - 1));
				count += _putchar(*p);
			}
		}
		else
		{
			_putchar(*p);
			count++;
		}
		p++;
	}
	va_end(args);
	return (count);
}

