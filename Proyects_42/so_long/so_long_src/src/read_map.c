/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:42:49 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/12 09:24:42 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_line(t_data_struct *data, char *line, int fd, int i)
{
	if (!line[0])
		ft_free_all(data, line, fd, 1);
	if (ft_strchr(line, '\n'))
		line[ft_strlen(line) - 1] = '\0';
	if (i == 0)
		data->map_width = ft_strlen(line);
	else if (ft_strlen(line) != (size_t)data->map_width)
		ft_free_all(data, line, fd, 1);
	if (i >= data->map_height)
		ft_free_all(data, line, fd, 1);
	data->map[i] = ft_strdup(line);
	if (!data->map[i])
		ft_free_all(data, line, fd, 3);
}

void	ft_fill_map(t_data_struct *data, char *pre_map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(pre_map, O_RDONLY);
	if (fd < 0)
		ft_free_all(data, NULL, -1, 2);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_validate_line(data, line, fd, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (i < data->map_height)
		ft_free_all(data, NULL, fd, 1);
	close(fd);
}

int	ft_count_lines(char *pre_map)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(pre_map, O_RDONLY);
	if (fd < 0)
		return (0);
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

void	ft_read_map(t_data_struct *data, char *pre_map)
{
	int	i;

	data->map_height = ft_count_lines(pre_map);
	if (!data->map_height)
		ft_error("Error\nEmpty map file\n");
	data->map = (char **)ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		ft_error("Error\nFailed to allocate map memory\n");
	ft_fill_map(data, pre_map);
	ft_validate_map(data);
	i = 0;
	while (i < data->map_height)
		ft_printf("%s\n", data->map[i++]);
}
