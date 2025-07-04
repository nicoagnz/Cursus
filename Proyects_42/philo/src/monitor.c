/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:59:08 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/29 09:38:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death_meals(t_data *data)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < data->nb_philos)
	{
		current_time = ft_get_current_time();
		if (data->meals_required != -1
			&& data->philos[i].meals_eaten < data->meals_required)
			break ;
		if (current_time - data->philos[i].last_meal >= data->time_to_die)
		{
			data->someone_died = 1;
			data->dead_philo = &data->philos[i];
			return (1);
		}
		i++;
	}
	if (i == data->nb_philos && data->meals_required != -1)
	{
		data->someone_died = 1;
		data->dead_philo = NULL;
		return (2);
	}
	return (0);
}

void	*ft_monitor_routine(void *av)
{
	t_data	*data;
	int		res;

	data = (t_data *)av;
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		res = ft_check_death_meals(data);
		pthread_mutex_unlock(&data->death_mutex);
		if (res == 1)
		{
			ft_print_status(data->dead_philo, "died");
			return (NULL);
		}
		if (res == 2)
			return (NULL);
		usleep(5000);
	}
	return (NULL);
}
