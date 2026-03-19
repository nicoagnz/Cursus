/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:17:15 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/03/16 13:02:51 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**ft_read_file(char *file)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;

	lines = malloc(sizeof(char *) * (count_lines(file) + 1));
	if (!lines)
		ft_handler_error("Malloc failed");
	fd = open_file(file);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_strtrim_newline(line);
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
