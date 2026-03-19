/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_contract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:59:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:03:22 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_rgb_valid(int c[3])
{
	return (c[0] >= 0 && c[0] <= 255
		&& c[1] >= 0 && c[1] <= 255
		&& c[2] >= 0 && c[2] <= 255);
}

void	validate_render_contract(t_game *game)
{
	if (!game || !game->map || !game->map->map)
		ft_handler_error("Error\nRender contract: map not initialized");
	if (game->map->map_width <= 0 || game->map->map_height <= 0)
		ft_handler_error("Error\nRender contract: invalid map size");
	if (!is_rgb_valid(game->config_map.floor_color))
		ft_handler_error("Error\nRender contract: invalid floor color");
	if (!is_rgb_valid(game->config_map.ceiling_color))
		ft_handler_error("Error\nRender contract: invalid ceiling color");
	if (!game->config_map.tex_no || !game->config_map.tex_so
		|| !game->config_map.tex_we || !game->config_map.tex_ea)
		ft_handler_error("Error\nRender contract: missing textures");
}
