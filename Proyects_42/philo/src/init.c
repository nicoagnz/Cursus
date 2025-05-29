/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:58:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/28 10:49:08 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		ft_error("Error\nMemory allocation failed");
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			ft_error("Error\nFailed to init fork mutex");
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL))
		ft_error("Error\nFailed to init print mutex");
	if (pthread_mutex_init(&data->death_mutex, NULL))
		ft_error("Error\nFailed to init death mutex");
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		i++;
	}
}

void	ft_init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		ft_error("Error\nMemory allocation failed");
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].data = data;
		i++;
	}
}

void	ft_init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->meals_required = ft_atol(av[5]);
	else
		data->meals_required = -1;
	data->someone_died = 0;
	data->start_time = ft_get_current_time();
	if (data->nb_philos < 1 || data->nb_philos > 200
		|| data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || (ac == 6 && data->meals_required <= 0))
		ft_error("Error\nInvalid arguments");
}
