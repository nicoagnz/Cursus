/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotina <nikotina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:28:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/18 12:10:06 by nikotina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	copy_map_line(char *dst, char *src, int width)
{
	int	len;

	ft_memset(dst, ' ', width);
	dst[width] = '\0';
	len = ft_strlen(src);
	if (len > 0 && src[len - 1] == '\n')
		len--;
	if (len > width)
		len = width;
	ft_memcpy(dst, src, len);
}

static char	**ft_rectangular_map(char **lines, int start, int height, int width)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(width + 1);
		if (!map[i])
		{
			free_partial_map(map, i);
			return (NULL);
		}
		copy_map_line(map[i], lines[start + i], width);
		i++;
	}
	map[height] = NULL;
	return (map);
}

static int	ft_check_no_extra(char **lines, int index)
{
	while (lines[index])
	{
		if (*ft_skip_spaces(lines[index]) != '\0')
			return (ft_handler_error("Extra content after map"));
		index++;
	}
	return (0);
}

int	ft_parse_map(t_game *game, char **lines, int start)
{
	int	height;
	int	width;

	height = ft_get_map_height(lines, start);
	if (height <= 0)
		return (ft_handler_error("Invalid or empty map"));
	width = ft_get_map_width(lines, start, height);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_handler_error("Malloc failed"));
	game->map->map = ft_rectangular_map(lines, start, height, width);
	if (!game->map->map)
		return (ft_handler_error("Malloc failed"));
	game->map->map_height = height;
	game->map->map_width = width;
	if (ft_check_no_extra(lines, start + height) != 0)
		return (1);
	return (0);
}
