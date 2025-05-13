/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:22:19 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 12:24:55 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <../MLX42/include/MLX42/MLX42.h>
# include "libft.h"

# define TILE_SIZE 64

typedef struct s_texture_struct
{
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collec;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
}	t_texture_struct;

typedef struct s_data_struct
{
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	t_texture_struct	textures;
	int					x;
	int					y;
	mlx_image_t			*img_wall;
	mlx_image_t			*img_floor;
	mlx_image_t			*img_player;
	mlx_image_t			*img_collec; // collect
	mlx_image_t			*img_exit;
	int					collec_count; // collect
	int					move_count;
	int					px;
	int					py;
	int					new_x;
	int					new_y;
}	t_data_struct;

typedef struct s_validate_struct
{
	int		player_count;
	int		exit_count;
	int		collec_count; // collect
	char	*visited;
	char	*visited_for_exit;
	int		px;
	int		py;
	int		x;
	int		y;
}	t_validate_struct;

// READ MAP
void	ft_read_map(t_data_struct *data, char *pre_map);

// UTILS READ MAP
int		ft_count_lines(char *pre_map);
void	ft_fill_map(t_data_struct *data, char *pre_map);
void	ft_validate_line(t_data_struct *data, char *line, int fd, int i);

// VERIFY MAP
void	ft_validate_map(t_data_struct *data);
void	ft_verify_map_borders(t_data_struct *data);
void	ft_verify_elements(t_data_struct *data, t_validate_struct *validate);
void	ft_find_player(t_data_struct *data);
void	ft_init_validate_struct(t_validate_struct *validate,
			t_data_struct *data);
void	ft_check_path(t_data_struct *data, t_validate_struct *validate);
void	ft_found_player(t_data_struct *data, t_validate_struct *validate);
void	ft_flood_fill(t_data_struct *data, int px, int py, char *visited);
void	ft_flood_fill_for_exit(t_data_struct *data, int px, int py, char
			*visited);
void	ft_check_collectibles(t_data_struct *data, t_validate_struct *validate);
void	ft_check_exit(t_data_struct *data, t_validate_struct *validate);

// MLX
void	ft_setup_game(t_data_struct *data);
void	ft_load_texture(t_data_struct *data);

// RENDER IMG
void	ft_load_texture(t_data_struct *data);
void	ft_render_map(t_data_struct *data);
void	ft_load_wall(t_data_struct *data);
void	ft_load_floor(t_data_struct *data);
void	ft_load_player(t_data_struct *data);
void	ft_load_collectable(t_data_struct *data);
void	ft_load_exit(t_data_struct *data);
void	ft_hook(mlx_key_data_t key_data, void *data_param);
void	ft_keys(mlx_key_data_t key_data, t_data_struct *data);
void	ft_check_close(void *data_param);

// OTHER FUNCION
void	ft_error(char *str);
void	ft_free_all(t_data_struct *data, char *line, int fd, int code);
void	ft_free_validate(t_validate_struct *validate);

#endif