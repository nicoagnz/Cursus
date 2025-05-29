/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:03:06 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:55:53 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(long tmp, char **arg, int i)
{
	i++;
	while (arg[i])
	{
		if (ft_atol(arg[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

static int	has_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check(long tmp, char **arg, int argc, int i)
{
	if (has_duplicate(tmp, arg, i))
		ft_error("Error\n", arg, argc);
	if (!has_num(arg[i]))
		ft_error("Error\n", arg, argc);
	if (tmp < -2147483648 || tmp > 2147483647)
		ft_error("Error\n", arg, argc);
}

void	check_av(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	if (ac == 2 && inva_input(av[1]))
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i++;
		arg = av;
	}
	while (arg[i])
	{
		tmp = ft_atol(arg[i]);
		check(tmp, arg, ac, i);
		i++;
	}
	if (ac == 2)
		ft_free((void **)arg);
}
