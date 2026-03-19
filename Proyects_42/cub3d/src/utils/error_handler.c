/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:25:51 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:00:27 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_validate_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit (1);
}

int	ft_handler_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (1);
}
