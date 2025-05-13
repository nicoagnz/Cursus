/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:57:51 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 12:21:55 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_collectibles(t_data_struct *data, t_validate_struct *validate)
{
	ft_found_player(data, validate);
	ft_flood_fill(data, validate->px, validate->py, validate->visited);
	validate->y = 0;
	while (validate->y < data->map_height)
	{
		validate->x = 0;
		while (validate->x < data->map_width)
		{
			if (data->map[validate->y][validate->x] == 'C' &&
				!validate->visited[validate->y * data->map_width + validate->x])
			{
				ft_free_validate(validate);
				ft_free_all(data, NULL, -1, 5);
			}
			validate->x++;
		}
		validate->y++;
	}
}

void	ft_check_exit(t_data_struct *data, t_validate_struct *validate)
{
	if (!validate->visited_for_exit)
	{
		ft_free_validate(validate);
		ft_free_all(data, NULL, -1, 4);
	}
	ft_flood_fill_for_exit(data, validate->px,
		validate->py, validate->visited_for_exit);
	validate->y = 0;
	while (validate->y < data->map_height)
	{
		validate->x = 0;
		while (validate->x < data->map_width)
		{
			if (data->map[validate->y][validate->x] == 'E' &&
				!validate->visited_for_exit[validate->y
				* data->map_width + validate->x])
			{
				ft_free_validate(validate);
				ft_free_all(data, NULL, -1, 5);
			}
			validate->x++;
		}
		validate->y++;
	}
}
