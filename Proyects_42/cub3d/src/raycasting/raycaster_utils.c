/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:50:34 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/12 12:55:20 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_dda_step(t_game *game, double ray_dir_x,
	double ray_dir_y, t_dda *dda)
{
	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player.x)
			* dda->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player.y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player.y)
			* dda->delta_dist_y;
	}
}

int	is_wall_cell(t_game *game, int map_x, int map_y)
{
	size_t	row_len;

	if (!game || !game->map || !game->map->map)
		return (1);
	if (map_y < 0 || map_y >= game->map->map_height)
		return (1);
	row_len = ft_strlen(game->map->map[map_y]);
	if (map_x < 0 || (size_t)map_x >= row_len)
		return (1);
	if (game->map->map[map_y][map_x] == '1'
		|| game->map->map[map_y][map_x] == ' ')
		return (1);
	return (0);
}

double	compute_perp_dist(t_game *game, t_dda *dda)
{
	double	perp_dist;

	(void)game;
	if (dda->side == 0)
		perp_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		perp_dist = dda->side_dist_y - dda->delta_dist_y;
	if (perp_dist < MIN_PERP_DIST)
		perp_dist = MIN_PERP_DIST;
	return (perp_dist);
}
