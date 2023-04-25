#include "main.h"

int	ft_checkmate(const char c, va_list ap)
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
			count += ft_checkmate(s[i], ap);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

/*int main()
{
	int x = '%';
	ft_printf("%%", x);
}*/
