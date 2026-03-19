/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:50:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/17 12:28:49 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_str_isdigits(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strtrim_newline(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == '\r' || ft_is_space(str[i])))
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

void	free_partial_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
