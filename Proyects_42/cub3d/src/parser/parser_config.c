/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:25:48 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/17 12:29:53 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_rgb_values(int color[3], char **rgb)
{
	char	*num;
	int		i;

	i = 0;
	while (i < 3)
	{
		num = ft_skip_spaces(rgb[i]);
		ft_strtrim_newline(num);
		if (!ft_str_isdigits(num))
		{
			return (ft_handler_error("Color must be numeric"));
		}
		color[i] = ft_atoi(num);
		if (color[i] < 0 || color[i] > 255)
		{
			return (ft_handler_error("Color out of range (0-255)"));
		}
		i++;
	}
	return (0);
}

static int	check_rgb_count(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		ft_free_split(rgb);
		return (ft_handler_error("Invalid color format"));
	}
	return (0);
}

static int	ft_parse_color(int color[3], int *flag, char *p)
{
	char	**rgb;

	p = ft_skip_spaces(p);
	if (validate_color_input(p, *flag) != 0)
		return (1);
	rgb = ft_split(p, ',');
	if (!rgb)
		return (ft_handler_error("Malloc failed"));
	if (check_rgb_count(rgb) != 0)
		return (1);
	if (parse_rgb_values(color, rgb) != 0)
	{
		ft_free_split(rgb);
		return (1);
	}
	ft_free_split(rgb);
	*flag = 1;
	return (0);
}

static int	ft_parse_texture(char **tex_field, int *flag, char *p)
{
	char	*start;
	char	*end;
	char	*path;

	p = ft_skip_spaces(p);
	if (*flag)
		return (ft_handler_error("Duplicate texture definition"));
	if (*p == '\0')
		return (ft_handler_error("Texture path missing"));
	start = p;
	while (*p && !ft_is_space(*p))
		p++;
	end = p;
	if (*p != '\0')
	{
		p = ft_skip_spaces(p);
		if (*p != '\0')
			return (ft_handler_error("Extra token after texture path"));
	}
	path = ft_substr(start, 0, end - start);
	if (!path)
		return (ft_handler_error("Malloc failed"));
	*tex_field = path;
	*flag = 1;
	return (0);
}

int	ft_parse_config_line(t_game *game, char *line)
{
	char	*p;

	p = ft_skip_spaces(line);
	if (ft_strncmp(p, "NO", 2) == 0)
		return (ft_parse_texture(&game->config_map.tex_no,
				&game->config_map.no_set, p + 2));
	else if (ft_strncmp(p, "SO", 2) == 0)
		return (ft_parse_texture(&game->config_map.tex_so,
				&game->config_map.so_set, p + 2));
	else if (ft_strncmp(p, "WE", 2) == 0)
		return (ft_parse_texture(&game->config_map.tex_we,
				&game->config_map.we_set, p + 2));
	else if (ft_strncmp(p, "EA", 2) == 0)
		return (ft_parse_texture(&game->config_map.tex_ea,
				&game->config_map.ea_set, p + 2));
	else if (p[0] == 'F')
		return (ft_parse_color(game->config_map.floor_color,
				&game->config_map.floor_set, p + 1));
	else if (p[0] == 'C')
		return (ft_parse_color(game->config_map.ceiling_color,
				&game->config_map.ceiling_set, p + 1));
	else
		return (ft_handler_error("Invalid config identifier"));
}
