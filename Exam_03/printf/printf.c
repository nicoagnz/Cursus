
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_put_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_s(char *str)
{
	int count = 0, i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		count += write(1, &str[i++], 1);
	return (count);
}

int	ft_put_nb(int nb)
{
	int count = 0;

	if (nb == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_put_c("-");
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_put_nb(nb / 10);
	count += ft_put_c((nb % 10) + '0');
	return (count);
}

int	ft_put_x(unsigned int nb)
{
	int	count = 0;
	char *hexa = "0123456789abcdef";

	if (nb >= 16)
		count += ft_put_x(nb / 16);
	count += ft_put_c(hexa[nb % 16]);
	return (count);
}

int	ft_format(const char c, va_list av)
{
	int	count = 0;
	if(c == 's')
		count += ft_put_s(va_arg(av, char *));
	else if (c == 'd')
		count += ft_put_nb(va_arg(av, int));
	else if (c == 'x')
		count += ft_put_x(va_arg(av, unsigned int));
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	av;
	int		count = 0, i = 0;

	if (!str)
		return 0;
	va_start(av, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += ft_format(str[i], av);
		}
		else
			count += write(1, str[i], 1);
		i++;
	}
	va_end(av);
	return (count);
}
