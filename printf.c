#include "main.h"

/**
 *_printf - function that produces output according to a format
 *@format: the format specifiers
 *Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, printed = 0;
	char *str;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					printed += _putchar((char)va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char*);
					for (i = 0; str[i]; i++)
						printed += _putchar(str[i]);
					break;
				case '%':
					printed += _putchar('%');
					break;
				case '\0':
					return (-1);
				case 'd':
				case 'i':
					printed += _putdigit(va_arg(args, int));
					break;
				default:
					printed += _putchar('%');
					format--;
					break;
			}
		}
		else
		{
			printed += _putchar(*format);
		}
			format++;
	}
	va_end(args);
	return (printed);
}
