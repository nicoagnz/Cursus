/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:39:36 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/29 09:38:14 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = ft_get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	ft_print_status(philo, "is eating");
	ft_precise_msleep(philo->data->time_to_eat * 1000, philo->data);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}

void	*ft_philo_routine(void *av)
{
	t_philo	*philo;

	philo = (t_philo *)av;
	if (philo->data->nb_philos == 1)
	{
		ft_print_status(philo, "has taken a fork");
		ft_precise_msleep(philo->data->time_to_die * 1000, philo->data);
	}
	if (philo->id % 2 == 0)
		ft_precise_msleep(philo->data->time_to_eat * 500, philo->data);
	while (philo->data->nb_philos != 1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->someone_died)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		ft_print_status(philo, "is thinking");
		ft_eat(philo);
		ft_print_status(philo, "is sleeping");
		ft_precise_msleep(philo->data->time_to_sleep * 1000, philo->data);
	}
	return (NULL);
}

void	ft_start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, ft_philo_routine,
				&data->philos[i]))
			ft_error("Error\nFailed to create philosopher thread");
		i++;
	}
	if (pthread_create(&monitor, NULL, ft_monitor_routine, data))
		ft_error("Error\nFailed to create monitor thread");
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			ft_error("Error\nFailed to join philosopher thread");
		i++;
	}
	if (pthread_join(monitor, NULL))
		ft_error("Error\nFailed to join monitor thread");
}
