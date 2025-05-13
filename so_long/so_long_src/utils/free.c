/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:28:21 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/13 09:20:10 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_code(int code)
{
	if (code == 1)
		ft_error("Error\nInvalid map configuration\n");
	else if (code == 2)
		ft_error("Error\nMap file error\n");
	else if (code == 3)
		ft_error("Error\nMemory allocation failed\n");
	else if (code == 4)
		ft_error("Error\nGraphics initialization failed\n");
	else if (code == 5)
		ft_error("Error\nNo valid path in map\n");
}

void	ft_delete_texture(t_data_struct *data)
{
	if (data->textures.wall)
	{
		mlx_delete_texture(data->textures.wall);
		data->textures.wall = NULL;
	}
	if (data->textures.floor)
	{
		mlx_delete_texture(data->textures.floor);
		data->textures.floor = NULL;
	}
	if (data->textures.player)
	{
		mlx_delete_texture(data->textures.player);
		data->textures.player = NULL;
	}
	if (data->textures.collec)
	{
		mlx_delete_texture(data->textures.collec);
		data->textures.collec = NULL;
	}
	if (data->textures.exit)
	{
		mlx_delete_texture(data->textures.exit);
		data->textures.exit = NULL;
	}
}

void	ft_free_all(t_data_struct *data, char *line, int fd, int code)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_height && data->map[i])
			free(data->map[i++]);
		free(data->map);
		data->map = NULL;
	}
	if (data->textures.wall || data->textures.floor || data->textures.player
		|| data->textures.collec || data->textures.exit)
		ft_delete_texture(data);
	if (data->mlx)
		mlx_terminate(data->mlx);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (code != 0)
		ft_error_code(code);
	else if (code == 0)
		exit (0);
}

void	ft_free_validate(t_validate_struct *validate)
{
	if (validate)
	{
		if (validate->visited)
			free(validate->visited);
		if (validate->visited_for_exit)
			free(validate->visited_for_exit);
		free(validate);
	}
}
