/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:17:07 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/12 11:17:27 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_spawn(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	set_dir(t_player *p, double x, double y)
{
	p->dir_x = x;
	p->dir_y = y;
}

void	set_plane(t_player *p, double x, double y)
{
	p->plane_x = x;
	p->plane_y = y;
}
