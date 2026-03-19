/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:40:03 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 12:21:15 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_openfd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

void	ft_validate_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
		ft_validate_error("Usage: ./cub3d <map.cub>");
	len = ft_strlen(av[1]);
	if (len < 5 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
		ft_validate_error("Error\nMap file must have .cub extension");
	if (ft_openfd(av[1]) < 0)
		ft_validate_error("Error\nCould not open file");
}
