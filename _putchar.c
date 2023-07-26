#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
  * _putdigit - writes the digit num to stdout
  *@num: number to check
  *Return: no of counted digits
  */
int _putdigit(int num)
{
	int printed = 0, divisor = 1, digit;

	if (num < 0)
	{
		printed += _putchar('-');
		num = -num;
	}
	while ((num / divisor) > 9)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = num / divisor;
		printed += _putchar('0' + digit);
		num %= divisor;
		divisor /= 10;
	}
	return (printed);
}
