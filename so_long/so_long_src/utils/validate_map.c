/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:38:01 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 09:40:41 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_data_struct *data)
{
	int		y;
	int		x;

	data->collec_count = 0;
	data->px = -1;
	data->py = -1;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'C')
				data->collec_count++;
			else if (data->map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_verify_elements(t_data_struct *data, t_validate_struct *validate)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
				validate->player_count++;
			else if (data->map[y][x] == 'C')
				validate->collec_count++;
			else if (data->map[y][x] == 'E')
				validate->exit_count++;
			else if (data->map[y][x] != '0' && data->map[y][x] != '1')
				ft_free_all(data, NULL, -1, 1);
			x++;
		}
		y++;
	}
	if (validate->player_count != 1 || validate->collec_count < 1
		|| validate->exit_count != 1)
		ft_free_all(data, NULL, -1, 1);
	ft_find_player(data);
}

void	ft_verify_map_borders(t_data_struct *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data->map_width)
	{
		if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
			ft_free_all(data, NULL, -1, 1);
		x++;
	}
	y = 0;
	while (y < data->map_height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
			ft_free_all(data, NULL, -1, 1);
		y++;
	}
}

void	ft_validate_map(t_data_struct *data)
{
	t_validate_struct	*validate;
	int					x;
	int					y;

	validate = (t_validate_struct *)ft_calloc(1, sizeof(t_validate_struct));
	if (!validate)
		ft_free_all(data, NULL, -1, 3);
	y = 0;
	x = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
			x++;
		if (x != data->map_width)
			ft_free_all(data, NULL, -1, 1);
		y++;
	}
	ft_init_validate_struct(validate, data);
	ft_verify_map_borders(data);
	ft_verify_elements(data, validate);
	ft_check_path(data, validate);
	ft_free_validate(validate);
}
