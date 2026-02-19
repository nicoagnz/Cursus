/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:59:35 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:54:45 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

typedef enum e_validate_error
{
	VALIDATE_OK,
	VALIDATE_ERROR
}	t_validate_error;

typedef struct s_map
{
	char **map;
	int	map_width;
	int	map_height;
}	t_map;

typedef struct s_game
{
	t_map* map;
}	t_game;

int		ft_validate_args(int ac, char **av);

// FREE
int	ft_error_handler(char *error_msg, t_game *game);
void	ft_free_game(t_game *game);


int		ft_openfd(char *file);

#endif
