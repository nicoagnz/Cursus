/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:16:50 by ctaboada          #+#    #+#             */
/*   Updated: 2025/10/14 11:30:28 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

void	exec_builtin(t_data *data, t_cmd *cmd)
{
	if (!cmd || !cmd->av || !cmd->av[0])
		return ;
	if (!ft_strcmp(cmd->av[0], "cd"))
		ft_builtin_cd(cmd->av, data);
	else if (!ft_strcmp(cmd->av[0], "pwd"))
		ft_builtin_pwd();
	else if (!ft_strcmp(cmd->av[0], "echo"))
		ft_builtin_echo(cmd->av);
	else if (!ft_strcmp(cmd->av[0], "export"))
		data->env = ft_builtin_export(cmd->av, data->env);
	else if (!ft_strcmp(cmd->av[0], "unset"))
		data->env = ft_builtin_unset(cmd->av, data->env);
	else if (!ft_strcmp(cmd->av[0], "env"))
		ft_builtin_env(data->env);
	else if (!ft_strcmp(cmd->av[0], "exit"))
		ft_builtin_exit(cmd->av, data);
}
