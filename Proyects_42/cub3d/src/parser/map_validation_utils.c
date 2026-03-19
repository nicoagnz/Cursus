/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:01:41 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:01:33 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_map_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
		i++;
	game->map->map_height = i;
	game->map->map_width = ft_strlen(game->map->map[0]);
}

int	ft_validate_map_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			if (!ft_valid_map_char(game->map->map[y][x]))
				return (ft_handler_error("Invalid map character"));
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_validate_player(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			if (ft_strchr("NSEW", game->map->map[y][x]))
			{
				game->player.x = x;
				game->player.y = y;
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ft_handler_error("Map must contain exactly one player"));
	return (0);
}
