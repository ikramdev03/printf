
#include "main.h"

int	ft_putstr(const char *s)
{	
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
