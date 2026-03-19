/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:29:31 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/19 12:40:46 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_color_range(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (ft_handler_error("Color out of range"));
		i++;
	}
	return (0);
}

static int	validate_colors(t_config *cfg)
{
	if (!cfg->floor_set || !cfg->ceiling_set)
		return (ft_handler_error("Missing floor or ceiling color"));
	if (validate_color_range(cfg->floor_color) != 0)
		return (1);
	if (validate_color_range(cfg->ceiling_color) != 0)
		return (1);
	return (0);
}

static int	validate_textures(t_config *cfg)
{
	if (*cfg->tex_no == '\0'
		|| *cfg->tex_so == '\0'
		|| *cfg->tex_we == '\0'
		|| *cfg->tex_ea == '\0')
		return (ft_handler_error("Empty texture path"));
	if (check_texture_file(cfg->tex_no) != 0)
		return (1);
	if (check_texture_file(cfg->tex_so) != 0)
		return (1);
	if (check_texture_file(cfg->tex_we) != 0)
		return (1);
	if (check_texture_file(cfg->tex_ea) != 0)
		return (1);
	return (0);
}

int	ft_validate_config(t_game *game)
{
	if (validate_textures(&game->config_map) != 0)
		return (1);
	if (validate_colors(&game->config_map) != 0)
		return (1);
	return (0);
}
