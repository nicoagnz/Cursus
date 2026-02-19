/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:32:08 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 10:39:13 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_openfd(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error_handler("Error: Could not open file");
		return (-1);
	}
	return (fd);
}
