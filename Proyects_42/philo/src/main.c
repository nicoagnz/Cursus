/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:15:40 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/30 10:58:54 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->philos);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_check_args(ac, av);
	ft_init_data(&data, ac, av);
	ft_init_philos(&data);
	ft_init_mutex(&data);
	ft_start_simulation(&data);
	ft_cleanup(&data);
	return (0);
}
