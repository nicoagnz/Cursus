/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:25:51 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:50:13 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_error_handler(char *error_msg, t_game *game)
{
	ft_putendl_fd(error_msg, 2);
	if (game)
		ft_free_game(game);
	exit (1);
}
