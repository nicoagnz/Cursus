/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:47:28 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/17 12:19:12 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map(t_map **map_ptr)
{
	t_map	*map;
	int		i;

	map = *map_ptr;
	if (map)
	{
		if (map->map)
		{
			i = 0;
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
		*map_ptr = NULL;
	}
}

static int	parser_cleanup(t_game *game, char **file_lines)
{
	free_map(&game->map);
	if (game->config_map.tex_no)
		free(game->config_map.tex_no);
	if (game->config_map.tex_so)
		free(game->config_map.tex_so);
	if (game->config_map.tex_we)
		free(game->config_map.tex_we);
	if (game->config_map.tex_ea)
		free(game->config_map.tex_ea);
	ft_free_split(file_lines);
	return (1);
}

int	parser(t_game *game, char *file)
{
	char	**file_lines;

	file_lines = ft_read_file(file);
	if (ft_parse_file(game, file_lines) != 0)
		return (parser_cleanup(game, file_lines));
	if (ft_validate_config(game) != 0)
		return (parser_cleanup(game, file_lines));
	if (ft_validate_map(game) != 0)
		return (parser_cleanup(game, file_lines));
	ft_free_split(file_lines);
	return (0);
}
