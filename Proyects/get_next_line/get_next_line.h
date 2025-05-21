/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:08:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/31 09:51:46 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *str);
char	*ft_correct_line(char *line);
char	*ft_rest_line(char *line);
char	*ft_strjoin(char *s1, char*s2);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *s);

#endif
