/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:53:59 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/15 09:12:36 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement(t_data_struct *data)
{
	if (data->map[data->new_y][data->new_x] == '1' ||
		(data->map[data->new_y][data->new_x] == 'E' &&
		data->collect_count != 0))
		return ;
	data->move_count++;
	printf("Moves: %i\n", data->move_count);
}

void	ft_keys(mlx_key_data_t key_data, t_data_struct *data)
{
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		ft_free_all(data, NULL, -1, 0);
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
	{
		data->new_y--;
		ft_movement(data);
	}
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
	{
		data->new_y++;
		ft_movement(data);
	}
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
	{
		data->new_x--;
		ft_movement(data);
	}
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
	{
		data->new_x++;
		ft_movement(data);
	}
}
