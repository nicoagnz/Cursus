/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:10:26 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/15 09:12:23 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_validate_struct(t_validate_struct *validate,
	t_data_struct *data)
{
	int	size;

	validate->collect_count = 0;
	validate->exit_count = 0;
	validate->player_count = 0;
	size = data->map_height * data->map_width;
	validate->visited = (char *)ft_calloc(size, sizeof(char));
	if (!validate->visited)
	{
		ft_free_validate(validate);
		ft_free_all(data, NULL, -1, 3);
	}
	validate->visited_for_exit = (char *)ft_calloc(size, sizeof(char));
	if (!validate->visited_for_exit)
	{
		ft_free_validate(validate);
		ft_free_all(data, NULL, -1, 3);
	}
	validate->px = -1;
	validate->py = 0;
	validate->x = 0;
	validate->y = 0;
}
