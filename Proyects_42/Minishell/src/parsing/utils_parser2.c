/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:54 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	open_heredoc_file(char **tmp_file, int saved_exit_code)
{
	int	fd;

	*tmp_file = ft_strdup("/tmp/.heredoc_tmp");
	if (!*tmp_file)
	{
		setup_signals();
		g_signal_exit_code = saved_exit_code;
		return (-1);
	}
	fd = open(*tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		free(*tmp_file);
		setup_signals();
		g_signal_exit_code = saved_exit_code;
		return (-1);
	}
	return (fd);
}

int	read_heredoc_lines(int fd, char *delimiter, char *tmp_file)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_signal_exit_code == 130 || !line)
		{
			if (line)
				free(line);
			close(fd);
			unlink("/tmp/.heredoc_tmp");
			free(tmp_file);
			return (-1);
		}
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	return (0);
}
