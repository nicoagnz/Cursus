/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:26:34 by nacuna-g          #+#    #+#             */
/*   Updated: 2024/12/27 11:09:16 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	len;
	int	sig;
	int	res;

	len = 0;
	sig = 1;
	res = 0;
	while (nptr[len] == ' ' || (nptr[len] >= 9 && nptr[len] <= 13))
		nptr++;
	if (nptr[len] == '+' || nptr[len] == '-')
	{
		if (nptr[len] == '-')
			sig = -1;
		len++;
	}
	while (nptr[len] >= '0' && nptr[len] <= '9')
		res = res * 10 + (nptr[len++] - '0');
	return (res * sig);
}

