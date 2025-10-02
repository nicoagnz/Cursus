/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:53:35 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/10/01 09:38:52 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_ordered_forks(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}

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
	int		someone_died;

	pthread_mutex_lock(&philo->data->death_mutex);
	someone_died = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!someone_died || !ft_strcmp(status, "died"))
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
