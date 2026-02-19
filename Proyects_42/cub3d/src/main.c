/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:00:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:56:07 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game game;
	
	ft_validate_args(ac, av);
	init_game(&game);
	parser_map(&game, av[1]);
	init_mlx(&game);
	start_game(&game);
	return (0);
}
