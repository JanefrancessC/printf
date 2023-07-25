#include "main.h"

/**
 *_printf - function that produces output according to a format
 *@format: the format specifiers
 *Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed = 0;
	char c, *str;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					_putchar(c);
					printed++;
					break;
				case 's':
					str = va_arg(args, char*);

					while (*str)
					{
						_putchar(*str);
						str++;
						printed++;
					}
					break;
				case '%':
					_putchar('%');
					printed++;
					break;
				default:
					_putchar('%');
					printed++;

					format--;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed++;
		}
			format++;
	}

	va_end(args);

	return (printed);
}
