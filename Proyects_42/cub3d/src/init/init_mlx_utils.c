/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:44:15 by ctaboada          #+#    #+#             */
/*   Updated: 2026/03/17 12:44:31 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fatal_init_error(t_game *game, char *msg)
{
	ft_free_game(game);
	ft_validate_error(msg);
}
