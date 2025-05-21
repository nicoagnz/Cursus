/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:03:13 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/21 11:22:27 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>    // Para fork, pipe, dup2, execve, access
# include <stdlib.h>    // Para malloc, free, exit
# include <fcntl.h>     // Para open
# include <sys/wait.h>  // Para waitpid
# include "libft.h"

// pipex.c
int		ft_pipex(char **av, char **env);

// process.c
void	ft_first_child(char **av, char **env, int *pipefd);
void	ft_second_child(char **av, char **env, int *pipefd);
int		ft_parent(char **av, char **env, int *pipefd);
int		ft_av_valid(char *av);

// execute_&_errors.c
void	ft_free_path(char **paths);
char	*ft_get_path(char *cmd, char **env);
void	ft_exec_cmd(char *av, char **env);
int		find_path(char **env);
void	ft_msg_error(char *msg);

#endif