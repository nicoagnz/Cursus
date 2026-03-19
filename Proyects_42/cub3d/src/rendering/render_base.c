/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:57:28 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/12 12:58:36 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static uint32_t	rgb_to_rga(int r, int g, int b)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | 0xFF);
}

void	render_base(t_game *game)
{
	int			x;
	int			y;
	uint32_t	ceiling;
	uint32_t	floor;

	ceiling = rgb_to_rga(game->config_map.ceiling_color[0],
			game->config_map.ceiling_color[1],
			game->config_map.ceiling_color[2]);
	floor = rgb_to_rga(game->config_map.floor_color[0],
			game->config_map.floor_color[1],
			game->config_map.floor_color[2]);
	y = 0;
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
		{
			if (y < game->win_h / 2)
				mlx_put_pixel(game->frame.img, x, y, ceiling);
			else
				mlx_put_pixel(game->frame.img, x, y, floor);
			x++;
		}
		y++;
	}
}
