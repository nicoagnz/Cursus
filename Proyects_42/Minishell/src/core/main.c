/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:05:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:57 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal_exit_code = 0;

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	printf(HEADER);
	init_data(&data, env);
	setup_signals();
	while (1)
	{
		if (init_prompt(&data))
			break ;
	}
	free_array(data.env);
	return (0);
}
