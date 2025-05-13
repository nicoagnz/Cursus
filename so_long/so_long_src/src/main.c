/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:43:59 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 09:24:59 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data_struct	*data;
	int				len;

	if (ac != 2)
		ft_error("Error\nUsage: ./so_long <map.ber>\n");
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(&av[1][len - 4], ".ber", 4) != 0)
		ft_error("Error\nMap file must have .ber extension\n");
	data = (t_data_struct *)ft_calloc(1, sizeof(t_data_struct));
	if (!data)
		ft_error("Error\nFailed to allocate memory\n");
	ft_read_map(data, av[1]);
	ft_setup_game(data);
	mlx_loop(data->mlx);
	ft_free_all(data, NULL, -1, -1);
	free(data);
	return (0);
}
