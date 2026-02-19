/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:40:03 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:51:41 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_validate_args(int ac, char **av)
{
	int len;

	if (ac != 2)
	{
		ft_error_handler("Usage: ./cub3d <map.cub>", NULL);
		return (VALIDATE_ERROR);
	}
	len = ft_strlen(av[1]);
	if (len < 5 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
	{
		ft_error_handler("Error\nMap file must have .cub extension", NULL);
		return (VALIDATE_ERROR);
	}
	if (ft_openfd(av[1]) < 0)
	{
		ft_error_handler("Error\nCould not open file", NULL);
		return(VALIDATE_ERROR);
	}
	return (VALIDATE_OK);
}
