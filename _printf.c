#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char * format, ...)
{
	va_list args;
	const char *p = format; 
	int count = 0;
	int offset = 0;
	int flags[5] = {0};
	int wid = 0;
	int precision = 0;
	int length = 0;
	char specifier;
	char c;
	char *str;
	long int digit;
	unsigned long int number_u_o_x_X_p;
	va_start(args,format);
	
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 0)
			{
				break;
			}
			offset = parse_flags(p, flags);
			p += offset;
			offset = parse_width(args, p, &wid);
			p += offset;
			offset = parse_precision(args, p, &precision);
			p += offset;
			offset = parse_length(p, &length);
			p += offset;
			specifier = parse_specifiers(p);
			
			if (specifier != 0)
			{
				switch (specifier)
				{
					case 'c':
						c = va_arg(args, int);
						count += convert_c(c, flags, wid);
						break;
					case 's':
						str = va_arg(args, char*);
						count += convert_s(str, flags, wid, precision);
						break;
					case 'd':
					case 'i':
						digit = va_arg(args, long int);
						count += convert_di(digit, flags, wid, precision, length);
						break;
					case '%':
						count += convert_percent(flags, wid);
						break;
					case 'b':
						digit = va_arg(args, unsigned int);
						count += convert_b(digit, flags, wid, precision, length);
						break;
					case 'u':
						number_u_o_x_X_p = va_arg(args, unsigned long int);
						count += convert_u(number_u_o_x_X_p, flags, wid, precision, length);
						break;
					case 'o':
						number_u_o_x_X_p = va_arg(args, unsigned long int);
						count += convert_o(number_u_o_x_X_p, flags, wid, precision, length);
						break;
					case 'x':
						number_u_o_x_X_p = va_arg(args, unsigned long int);
						count += convert_x(number_u_o_x_X_p, flags, wid, precision, length);
						break;
					case 'X':
						number_u_o_x_X_p = va_arg(args, unsigned long int);
						count += convert_X(number_u_o_x_X_p, flags, wid, precision, length);
						break;
					case 'S':
						str = va_arg(args, char *);
						count += convert_S(str, flags, wid, precision);
						break;
					case 'p':
						number_u_o_x_X_p = va_arg(args, unsigned long int );
						count += convert_p(number_u_o_x_X_p, flags, wid, precision);
						break;
					case 'r':
						str = va_arg(args, char*);
						count += convert_r(str, flags, wid, precision, length);
						break;
					case 'R':
						str = va_arg(args, char*);
						count += convert_R(str,flags,wid,precision,length);
						break;
				}
			}
			else
			{
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
	return count;
}

