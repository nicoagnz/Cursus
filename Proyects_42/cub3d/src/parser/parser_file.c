/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:14:13 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/17 12:29:01 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_config_line(char *line)
{
	char	*p;

	p = ft_skip_spaces(line);
	if (!p || *p == '\0')
		return (0);
	if ((ft_strncmp(p, "NO", 2) == 0
			|| ft_strncmp(p, "SO", 2) == 0
			|| ft_strncmp(p, "WE", 2) == 0
			|| ft_strncmp(p, "EA", 2) == 0)
		&& ft_is_space(p[2]))
		return (1);
	if ((p[0] == 'F' || p[0] == 'C') && ft_is_space(p[1]))
		return (1);
	return (0);
}

static int	ft_config_complete(t_config *config)
{
	if (!config->no_set || !config->so_set || !config->we_set
		|| !config->ea_set || !config->floor_set || !config->ceiling_set)
		return (0);
	return (1);
}

static int	parse_line_config(t_game *game, char *line)
{
	if (ft_parse_config_line(game, line) != 0)
		return (1);
	return (0);
}

static int	parse_line_map(t_game *game, char **lines, int i)
{
	if (!ft_config_complete(&game->config_map))
		return (ft_handler_error("Map found before config complete"));
	if (ft_parse_map(game, lines, i) != 0)
		return (1);
	return (0);
}

int	ft_parse_file(t_game *game, char **lines)
{
	char	*line;
	int		i;

	i = 0;
	while (lines[i])
	{
		line = ft_skip_spaces(lines[i]);
		if (*line == '\0')
			;
		else if (ft_is_config_line(line))
		{
			if (parse_line_config(game, line) != 0)
				return (1);
		}
		else if (ft_is_map_line(line))
		{
			if (parse_line_map(game, lines, i) != 0)
				return (1);
			return (0);
		}
		else
			return (ft_handler_error("Invalid line in config section"));
		i++;
	}
	return (ft_handler_error("No map found"));
}
