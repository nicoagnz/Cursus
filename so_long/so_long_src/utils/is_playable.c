/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:12:14 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 12:21:24 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill_for_exit(t_data_struct *data,
	int px, int py, char *visited)
{
	if (px < 0 || px >= data->map_width || py < 0 || py >= data->map_height)
		return ;
	if (data->map[py][px] == '1'
		|| visited[py * data->map_width + px])
		return ;
	visited[py * data->map_width + px] = 1;
	ft_flood_fill_for_exit(data, px + 1, py, visited);
	ft_flood_fill_for_exit(data, px - 1, py, visited);
	ft_flood_fill_for_exit(data, px, py + 1, visited);
	ft_flood_fill_for_exit(data, px, py - 1, visited);
}

void	ft_flood_fill(t_data_struct *data, int px, int py, char *visited)
{
	if (px < 0 || px >= data->map_width || py < 0 || py >= data->map_height)
		return ;
	if (data->map[py][px] == '1' || data->map[py][px] == 'E'
		|| visited[py * data->map_width + px])
		return ;
	visited[py * data->map_width + px] = 1;
	ft_flood_fill(data, px + 1, py, visited);
	ft_flood_fill(data, px - 1, py, visited);
	ft_flood_fill(data, px, py + 1, visited);
	ft_flood_fill(data, px, py -1, visited);
}

void	ft_found_player(t_data_struct *data, t_validate_struct *validate)
{
	while (validate->y < data->map_height)
	{
		validate->x = 0;
		while (validate->x < data->map_width)
		{
			if (data->map[validate->y][validate->x] == 'P')
			{
				validate->px = validate->x;
				validate->py = validate->y;
				break ;
			}
			validate->x++;
		}
		if (validate->px != -1)
			break ;
		validate->y++;
	}
	if (validate->px == -1)
		ft_error("Error\nPlayer not found");
}

void	ft_check_path(t_data_struct *data, t_validate_struct *validate)
{
	ft_check_collectibles(data, validate);
	ft_check_exit(data, validate);
}
