/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:15:49 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/15 09:13:43 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_texture(t_data_struct *data)
{
	data->textures.wall = mlx_load_png("textures/wall.png");
	data->textures.floor = mlx_load_png("textures/floor.png");
	data->textures.player = mlx_load_png("textures/player.png");
	data->textures.collect = mlx_load_png("textures/collectable.png");
	data->textures.exit = mlx_load_png("textures/exit.png");
	if (!data->textures.player || !data->textures.collect
		|| !data->textures.exit || !data->textures.floor
		|| !data->textures.wall)
		ft_free_all(data, NULL, -1, 4);
}

void	ft_render_map(t_data_struct *data)
{
	data->y = 0;
	while (data->y < data->map_height)
	{
		data->x = 0;
		while (data->x < data->map_width)
		{
			if (data->map[data->y][data->x] == '1')
				ft_load_wall(data);
			else if (data->map[data->y][data->x] == '0')
				ft_load_floor(data);
			else if (data->map[data->y][data->x] == 'P')
				ft_load_player(data);
			else if (data->map[data->y][data->x] == 'C')
				ft_load_collectible(data);
			else if (data->map[data->y][data->x] == 'E')
				ft_load_exit(data);
			data->x++;
		}
		data->y++;
	}
}

void	ft_hook(mlx_key_data_t key_data, void *data_param)
{
	t_data_struct	*data;

	data = (t_data_struct *)data_param;
	data->new_x = data->px;
	data->new_y = data->py;
	ft_keys(key_data, data);
	if (data->new_x >= 0 && data->new_x < data->map_width && data->new_y >= 0
		&& data->new_y < data->map_height
		&& data->map[data->new_y][data->new_x] != '1')
	{
		if (data->map[data->new_y][data->new_x] == 'C')
			data->collect_count--;
		if (data->map[data->new_y][data->new_x] == 'E' &&
			data->collect_count == 0)
			ft_free_all(data, NULL, -1, 0);
		if (data->map[data->new_y][data->new_x] == 'E')
			return ;
		data->map[data->py][data->px] = '0';
		data->map[data->new_y][data->new_x] = 'P';
		data->px = data->new_x;
		data->py = data->new_y;
		ft_render_map(data);
	}
}

void	ft_check_close(void *data_param)
{
	t_data_struct	*data;

	data = (t_data_struct *)data_param;
	if (!data->mlx->window)
		ft_free_all(data, NULL, -1, 0);
}

void	ft_setup_game(t_data_struct *data)
{
	data->mlx = mlx_init(data->map_width * TILE_SIZE,
			data->map_height * TILE_SIZE, "So Long", true);
	if (!data->mlx)
		ft_free_all(data, NULL, -1, 4);
	ft_load_texture(data);
	ft_render_map(data);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop_hook(data->mlx, ft_check_close, data);
}
