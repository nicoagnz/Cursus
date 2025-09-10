/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:59:08 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/09/10 11:47:44 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_data *data)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < data->nb_philos)
	{
		current_time = ft_get_current_time();
		if (current_time - data->philos[i].last_meal >= data->time_to_die)
		{
			data->someone_died = 1;
			data->dead_philo = &data->philos[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_meals(t_data *data)
{
	int	i;
	int	all_eaten;

	all_eaten = 1;
	i = 0;
	while (i < data->nb_philos)
	{
		if (data->meals_required != -1
			&& data->philos[i].meals_eaten < data->meals_required)
			all_eaten = 0;
		i++;
	}
	if (all_eaten && data->meals_required != -1)
	{
		data->someone_died = 1;
		data->dead_philo = NULL;
		return (1);
	}
	return (0);
}

void	*ft_monitor_routine(void *av)
{
	t_data	*data;
	int		meals_check;
	int		death_check;

	data = (t_data *)av;
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		meals_check = ft_check_meals(data);
		death_check = ft_check_death(data);
		pthread_mutex_unlock(&data->death_mutex);
		if (death_check)
		{
			ft_print_status(data->dead_philo, "died");
			return (NULL);
		}
		if (meals_check)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
