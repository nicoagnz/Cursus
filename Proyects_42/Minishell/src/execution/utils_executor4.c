/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:20:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:37 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_exit_status(t_data *data)
{
	if (g_signal_exit_code != 0)
	{
		data->exit_status = g_signal_exit_code;
		g_signal_exit_code = 0;
	}
	else
		data->exit_status = data->execute.exit_status;
}
