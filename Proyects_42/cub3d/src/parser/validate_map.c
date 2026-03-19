/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:06:19 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:03:12 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_check_cell(t_game *game, int x, int y)
{
	char	c;

	c = game->map->map[y][x];
	if (c == '0' || ft_strchr("NSEW", c))
	{
		if (y == 0 || x == 0
			|| y == game->map->map_height - 1
			|| x == game->map->map_width - 1)
			return (ft_handler_error("Map not closed"));
		if (game->map->map[y - 1][x] == ' '
			|| game->map->map[y + 1][x] == ' '
			|| game->map->map[y][x - 1] == ' '
			|| game->map->map[y][x + 1] == ' ')
			return (ft_handler_error("Map not closed"));
	}
	return (0);
}

static int	ft_validate_map_closed(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			if (ft_check_cell(game, x, y) != 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_validate_map(t_game *game)
{
	ft_set_map_dimensions(game);
	if (ft_validate_map_chars(game) != 0)
		return (1);
	if (ft_validate_player(game) != 0)
		return (1);
	if (ft_validate_map_closed(game) != 0)
		return (1);
	return (0);
}
