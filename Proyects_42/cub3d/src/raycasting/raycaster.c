/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:20:28 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 11:10:33 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_ray(t_game *game, int x,
			double *ray_dir_x, double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)game->win_w - 1.0;
	*ray_dir_x = game->player.dir_x
		+ game->player.plane_x * camera_x;
	*ray_dir_y = game->player.dir_y
		+ game->player.plane_y * camera_x;
}

static void	init_dda(t_game *game, t_dda *dda)
{
	dda->map_x = (int)game->player.x;
	dda->map_y = (int)game->player.y;
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1.0 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1.0 / dda->ray_dir_y);
	init_dda_step(game,
		dda->ray_dir_x,
		dda->ray_dir_y,
		dda);
}

static void	run_dda(t_game *game, t_dda *dda)
{
	while (1)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (is_wall_cell(game,
				dda->map_x,
				dda->map_y))
			break ;
	}
}

static void	draw_column(t_game *game, int x, t_dda *dda)
{
	t_texdraw	d;
	double		perp_dist;

	perp_dist = compute_perp_dist(game, dda);
	d.line_height = (int)(game->win_h / perp_dist);
	d.start = -d.line_height / 2 + game->win_h / 2;
	d.end = d.line_height / 2 + game->win_h / 2;
	if (d.start < 0)
		d.start = 0;
	if (d.end >= game->win_h)
		d.end = game->win_h - 1;
	d.perp_dist = perp_dist;
	draw_texture(game, x, dda, &d);
}

void	render_walls(t_game *game)
{
	int		x;
	t_dda	dda;

	if (!game || !game->mlx
		|| !game->map || !game->map->map)
		return ;
	x = 0;
	while (x < game->win_w)
	{
		init_ray(game, x,
			&dda.ray_dir_x,
			&dda.ray_dir_y);
		init_dda(game, &dda);
		run_dda(game, &dda);
		draw_column(game, x, &dda);
		x++;
	}
}
