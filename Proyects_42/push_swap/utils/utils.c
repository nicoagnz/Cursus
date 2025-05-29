/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:21:52 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:55:15 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str, char **arg, int ac)
{
	if (ac == 2)
		ft_free((void **)arg);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void	ft_free(void **clean)
{
	int	i;

	i = 0;
	while (clean[i])
		free(clean[i++]);
	free(clean);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;
	int		len;

	res = 0;
	len = 0;
	sign = 1;
	while (nptr[len] == ' ' || (nptr[len] >= 9 && nptr[len] <= 13))
		nptr++;
	if (nptr[len] == '-' || nptr[len] == '+')
	{
		if (nptr[len] == '-')
			sign = -1;
		len++;
	}
	while (nptr[len] >= '0' && nptr[len] <= '9')
		res = res * 10 + (nptr[len++] - '0');
	return (res * sign);
}

int	inva_input(char *str)
{
	int	final;

	final = ft_strlen(str);
	if (str[final] == ' ' && (ft_wcount(str) > 1))
		return (1);
	return (0);
}
