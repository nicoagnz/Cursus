/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotina <nikotina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:30:31 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/18 12:07:06 by nikotina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_game *game)
{
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;

	tex_no = mlx_load_png(game->config_map.tex_no);
	game->config_map.texture_no = tex_no;
	tex_so = mlx_load_png(game->config_map.tex_so);
	game->config_map.texture_so = tex_so;
	tex_we = mlx_load_png(game->config_map.tex_we);
	game->config_map.texture_we = tex_we;
	tex_ea = mlx_load_png(game->config_map.tex_ea);
	game->config_map.texture_ea = tex_ea;
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	game->win_w = 1024;
	game->win_h = 768;
}

void	init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	validate_render_contract(game);
	game->mlx = mlx_init(game->win_w, game->win_h, "Cub3D", true);
	if (!game->mlx)
		fatal_init_error(game, "Error\nFailed to initialize MLX");
	load_textures(game);
	game->frame.img = mlx_new_image(game->mlx, game->win_w, game->win_h);
	if (!game->frame.img)
		fatal_init_error(game, "Error\nFailed to create frame image");
	if (mlx_image_to_window(game->mlx, game->frame.img, 0, 0) < 0)
		fatal_init_error(game, "Error\nFailed to put attach frame to window");
	render_base(game);
}

static void	game_loop(void *param)
{
	t_game	*game;

	if (!param)
		return ;
	game = (t_game *)param;
	if (!game->mlx || !game->frame.img)
		return ;
	move_player(game);
	render_base(game);
	render_walls(game);
}

void	start_game(t_game *game)
{
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
