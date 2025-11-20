/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:50:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:08 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_error_child(t_child_error code, char *context)
{
	if (context)
	{
		ft_putstr_fd(context, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (code == CHILD_CMD_NOT_FOUND)
			ft_putendl_fd("command not found", STDERR_FILENO);
		else if (code == CHILD_EXEC_FAIL)
			ft_putendl_fd("execution failed", STDERR_FILENO);
		else if (code == CHILD_REDIR_FAIL)
			ft_putendl_fd("redirection failed", STDERR_FILENO);
		else if (code == CHILD_DUP_FAIL)
			ft_putendl_fd("dup2 failed", STDERR_FILENO);
		else
			ft_putendl_fd("unknown error", STDERR_FILENO);
	}
	else
		ft_putendl_fd("minishell: unknown child error", STDERR_FILENO);
	exit(code);
}
