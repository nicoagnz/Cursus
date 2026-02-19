/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:40:03 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 11:02:18 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_validate_args(int ac, char **av)
{
	int len;

	if (ac != 2)
	{
		ft_error_handler("Usage: ./cub3d <map.cub>");
		return (VALIDATE_ERROR);
	}
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".cub", 4) != 0)
		ft_error_handler("Error: Map file must have .cub extension");
	if (ft_openfd(av[1]) < 0)
	{
		ft_error_handler("Error: Could not open file");
		return(VALIDATE_ERROR);
	}
	return (VALIDATE_OK);
}
