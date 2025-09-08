/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:53:35 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/09/04 10:18:36 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_print_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->someone_died || !ft_strcmp(status, "died"))
	{
		time = ft_get_current_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

long	ft_atol(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] || i == 0)
		ft_error("Error\nInvalid number");
	return (res);
}

void	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		ft_error("Error\nInvalid number of arguments");
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				ft_error("Error\nAll arguments must be unsigned integers");
			j++;
		}
		i++;
	}
}
