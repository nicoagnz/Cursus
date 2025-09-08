/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:22:19 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/06/06 09:11:33 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_required;
	long			start_time;
	int				someone_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*dead_philo;
	t_philo			*philos;
}			t_data;

// MAIN FUNCTION
void	ft_check_args(int ac, char **av);
void	ft_init_data(t_data *data, int ac, char **av);
void	ft_init_philos(t_data *data);
void	ft_init_mutex(t_data *data);
void	ft_start_simulation(t_data *data);
void	*ft_philo_routine(void *av);
void	*ft_monitor_routine(void *av);

// UTILS
long	ft_atol(char *str);
void	ft_precise_msleep(long msec, t_data *data);
long	ft_get_current_time(void);
void	ft_print_status(t_philo *philo, char *status);
int		ft_strcmp(char *s1, char *s2);
void	ft_cleanup(t_data *data);

// ERROR HANDLER
void	ft_error(char *msg);

#endif