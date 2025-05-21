#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_put_c(char c)
{
	return (write(1, &c, 1));
}

int ft_put_s(char *s)
{
	int count = 0, len = 	0;

	if (!s)
		s = "(null)";
	while (s[len])
	{
		count += ft_put_c(s[len]);
		len++;
	}
	return (count);
}

int ft_put_d(int nb)
{
	int count = 0;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_put_d(nb / 10);
	count += ft_put_c((nb % 10) + '0');
	return (count);
}

int ft_put_x(unsigned int nb)
{
	char *hexa = "0123456789abcdef";
	int count = 0;

	if (nb >= 16)
		count += ft_put_x(nb / 16);
	count += ft_put_c(hexa[nb % 16]);
	return (count);
}

int	format(va_list av, char c)
{
	int count = 0;

	if (c == 's')
		count += ft_put_s(va_arg(av, char *));
	else if (c == 'd')
		count += ft_put_d(va_arg(av, int));
	else if (c == 'x')
		count += ft_put_x(va_arg(av, unsigned int));
	return (count);
}

int	ft_printf(char *s, ...)
{
	va_list	av;
	int count = 0, len = 0;

	if(!s)
		return (0);
	va_start(av, s);
	while (s[len])
	{
		if (s[len] == '%' && s[len + 1])
		{
			len ++;
			count += format(av, s[len]);
		}
		else
			count += write(1, &s[len], 1);
		len++;
	}
	va_end(av);
	return (count);
}

