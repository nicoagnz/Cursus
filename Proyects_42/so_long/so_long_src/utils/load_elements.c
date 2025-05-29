/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:48:41 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/15 09:12:47 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_wall(t_data_struct *data)
{
	if (!data->textures.wall)
		ft_free_all(data, NULL, -1, 4);
	if (!data->img_wall)
	{
		data->img_wall = mlx_texture_to_image(data->mlx, data->textures.wall);
		if (!data->img_wall)
			ft_free_all(data, NULL, -1, 4);
	}
	if (mlx_image_to_window(data->mlx, data->img_wall,
			data->x * TILE_SIZE, data->y * TILE_SIZE) == -1)
		ft_free_all(data, NULL, -1, 4);
}

void	ft_load_floor(t_data_struct *data)
{
	if (!data->textures.floor)
		ft_free_all(data, NULL, -1, 4);
	if (!data->img_floor)
	{
		data->img_floor = mlx_texture_to_image(data->mlx, data->textures.floor);
		if (!data->img_floor)
			ft_free_all(data, NULL, -1, 4);
	}
	if (mlx_image_to_window(data->mlx, data->img_floor,
			data->x * TILE_SIZE, data->y * TILE_SIZE) == -1)
		ft_free_all(data, NULL, -1, 4);
}

void	ft_load_player(t_data_struct *data)
{
	if (!data->textures.player)
		ft_free_all(data, NULL, -1, 4);
	ft_load_floor(data);
	if (!data->img_player)
	{
		data->img_player = mlx_texture_to_image(data->mlx,
				data->textures.player);
		if (!data->img_player)
			ft_free_all(data, NULL, -1, 4);
	}
	if (mlx_image_to_window(data->mlx, data->img_player,
			data->x * TILE_SIZE, data->y * TILE_SIZE) == -1)
		ft_free_all(data, NULL, -1, 4);
}

void	ft_load_collectible(t_data_struct *data)
{
	if (!data->textures.collect)
		ft_free_all(data, NULL, -1, 4);
	ft_load_floor(data);
	if (!data->img_collect)
	{
		data->img_collect = mlx_texture_to_image(data->mlx,
				data->textures.collect);
		if (!data->img_collect)
			ft_free_all(data, NULL, -1, 4);
	}
	if (mlx_image_to_window(data->mlx, data->img_collect,
			data->x * TILE_SIZE, data->y * TILE_SIZE) == -1)
		ft_free_all(data, NULL, -1, 4);
}

void	ft_load_exit(t_data_struct *data)
{
	if (!data->textures.exit)
		ft_free_all(data, NULL, -1, 4);
	ft_load_floor(data);
	if (!data->img_exit)
	{
		data->img_exit = mlx_texture_to_image(data->mlx, data->textures.exit);
		if (!data->img_exit)
			ft_free_all(data, NULL, -1, 4);
	}
	if (mlx_image_to_window(data->mlx, data->img_exit,
			data->x * TILE_SIZE, data->y * TILE_SIZE) == -1)
		ft_free_all(data, NULL, -1, 4);
}
