/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:16:47 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/12 12:17:09 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_get_map_height(char **lines, int start)
{
	int		i;
	int		height;
	char	*trim;

	i = start;
	height = 0;
	while (lines[i])
	{
		trim = ft_skip_spaces(lines[i]);
		if (*trim != '\0' && !ft_is_map_line(lines[i]))
			return (-1);
		height++;
		i++;
	}
	return (height);
}

int	ft_get_map_width(char **lines, int start, int height)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < height)
	{
		len = ft_strlen(lines[start + i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
