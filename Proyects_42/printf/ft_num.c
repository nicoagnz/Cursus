/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:05:17 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/22 10:01:09 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_i_putint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += ft_c_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_d_i_putint(n / 10);
	count += ft_c_putchar(n % 10 + '0');
	return (count);
}

int	ft_u_putint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_u_putint(n / 10);
	count += ft_c_putchar((n % 10) + '0');
	return (count);
}
