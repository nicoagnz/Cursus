/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by ctaboada          #+#    #+#             */
/*   Updated: 2026/03/10 10:56:47 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_textures(t_config *config)
{
	if (config->tex_no)
		free(config->tex_no);
	if (config->tex_so)
		free(config->tex_so);
	if (config->tex_we)
		free(config->tex_we);
	if (config->tex_ea)
		free(config->tex_ea);
	if (config->texture_no)
		mlx_delete_texture(config->texture_no);
	if (config->texture_so)
		mlx_delete_texture(config->texture_so);
	if (config->texture_we)
		mlx_delete_texture(config->texture_we);
	if (config->texture_ea)
		mlx_delete_texture(config->texture_ea);
}

static void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->map_height)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free(map);
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(&game->config_map);
	free_map(game->map);
	if (game->mlx && game->frame.img)
		mlx_delete_image(game->mlx, game->frame.img);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
