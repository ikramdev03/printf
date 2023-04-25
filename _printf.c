#include "main.h"

/**
 * ft_check - Checks the format specifier and prints the corresponding argument
 * @c: The format specifier to check
 * @ap: The argument list
 *
 * Return: The number of characters printed
 */

int	ft_check(const char c, va_list ap)
{
	int		count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, const char *));
	return (count);
}

/**
 * _printf - produces output according to format
 * @s: format in which output is produced
 * Return: Printed chars.
 */
int	_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	int			i;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_check(s[i], ap);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
