/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:46:16 by ctaboada          #+#    #+#             */
/*   Updated: 2026/03/17 11:04:04 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	add_movement(double *dx, double *dy, double add_x, double add_y)
{
	*dx += add_x;
	*dy += add_y;
}

void	handle_movement(t_game *game)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		add_movement(&dx, &dy,
			game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		add_movement(&dx, &dy,
			-game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		add_movement(&dx, &dy,
			-game->player.plane_x * MOVE_SPEED,
			-game->player.plane_y * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		add_movement(&dx, &dy,
			game->player.plane_x * MOVE_SPEED,
			game->player.plane_y * MOVE_SPEED);
	if (dx != 0 || dy != 0)
		try_move(game, dx, dy);
}
