/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:19:37 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/17 10:59:29 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_blocked(t_game *game, double x, double y)
{
	int		mx;
	int		my;
	size_t	row_len;

	if (!game || !game->map || !game->map->map)
		return (1);
	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= game->map->map_height)
		return (1);
	row_len = ft_strlen(game->map->map[my]);
	if (mx < 0 || (size_t)mx >= row_len)
		return (1);
	if (game->map->map[my][mx] == '1' || game->map->map[my][mx] == ' ')
		return (1);
	return (0);
}

static int	can_move_to(t_game *game, double x, double y)
{
	if (is_blocked(game, x, y))
		return (0);
	if (is_blocked(game, x - PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (0);
	if (is_blocked(game, x + PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (0);
	if (is_blocked(game, x - PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (0);
	if (is_blocked(game, x + PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (0);
	return (1);
}

void	try_move(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (can_move_to(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move_to(game, game->player.x, new_y))
		game->player.y = new_y;
}

static void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * c - game->player.dir_y * s;
	game->player.dir_y = old_dir_x * s + game->player.dir_y * c;
	game->player.plane_x = game->player.plane_x * c - game->player.plane_y * s;
	game->player.plane_y = old_plane_x * s + game->player.plane_y * c;
}

void	move_player(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	handle_movement(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, -ROT_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROT_SPEED);
}
