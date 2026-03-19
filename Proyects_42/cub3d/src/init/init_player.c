/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:09:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:01:25 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_orientation(t_player *p, char spawn)
{
	if (spawn == 'N')
	{
		set_dir(p, 0.0, -1.0);
		set_plane(p, 0.66, 0.0);
	}
	else if (spawn == 'S')
	{
		set_dir(p, 0.0, 1.0);
		set_plane(p, -0.66, 0.0);
	}
	else if (spawn == 'E')
	{
		set_dir(p, 1.0, 0.0);
		set_plane(p, 0.0, 0.66);
	}
	else if (spawn == 'W')
	{
		set_dir(p, -1.0, 0.0);
		set_plane(p, 0.0, -0.66);
	}
}

static void	process_spawn(t_game *game, int x, int y, int *count)
{
	char	c;

	c = game->map->map[y][x];
	if (is_spawn(c))
	{
		(*count)++;
		if (*count > 1)
			ft_handler_error("Error\nPlayer init: multiple spawns");
		game->player.x = (double)x + 0.5;
		game->player.y = (double)y + 0.5;
		set_player_orientation(&game->player, c);
		game->map->map[y][x] = '0';
	}
}

void	init_player(t_game *game)
{
	int	y;
	int	x;
	int	spawn_count;

	if (!game || !game->map || !game->map->map)
		ft_handler_error("Error\nPlayer init: map not initialized");
	spawn_count = 0;
	y = 0;
	while (y < game->map->map_height && game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			process_spawn(game, x, y, &spawn_count);
			x++;
		}
		y++;
	}
	if (spawn_count == 0)
		ft_handler_error("Error\nPlayer init: missing spawn");
}
