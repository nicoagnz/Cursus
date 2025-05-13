/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:13:25 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:51:32 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += format_str(str[i], &args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	format_str(const char str, va_list *args)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_c_putchar(va_arg(*args, int));
	else if (str == 's')
		count += ft_s_putstr(va_arg(*args, const char *));
	else if (str == 'p')
		count += ft_p_puntvoid(va_arg(*args, void *));
	else if (str == 'd' || str == 'i')
		count += ft_d_i_putint(va_arg(*args, int));
	else if (str == 'u')
		count += ft_u_putint(va_arg(*args, unsigned int));
	else if (str == 'x')
		count += ft_x_hexa(va_arg(*args, unsigned int));
	else if (str == 'X')
		count += ft_xx_hexa(va_arg(*args, unsigned int));
	else if (str == '%')
		count += write(1, "%", 1);
	return (count);
}
