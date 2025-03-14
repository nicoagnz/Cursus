/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:20:43 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/24 12:01:08 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_puntvoid(void *ptr)
{
	char		*hexa;
	int			count;
	int			i;
	char		str[25];
	uintptr_t	n;

	if (!ptr)
		return (write(1, "(nil)", 5));
	hexa = "0123456789abcdef";
	count = 0;
	i = 0;
	n = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	while (n != 0)
	{
		str[i++] = hexa[n % 16];
		n /= 16;
	}
	while (i--)
		count += ft_c_putchar(str[i]);
	return (count);
}

int	ft_x_hexa(unsigned int n)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (n >= 16)
		count += ft_x_hexa(n / 16);
	count += write(1, &hexa[n % 16], 1);
	return (count);
}

int	ft_xx_hexa(unsigned int n)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_xx_hexa(n / 16);
	count += ft_c_putchar(hexa[n % 16]);
	return (count);
}
