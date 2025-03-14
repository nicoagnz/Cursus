/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:03:13 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/12 11:42:44 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>      // perror(), printf()
# include <stdlib.h>     // malloc(), free(), exit()
# include <unistd.h>     // write(), fork(), close(), dup2(), execve(), pipe()
# include <sys/types.h>  // pid_t, etc.
# include <sys/wait.h>   // wait(), waitpid()
# include <fcntl.h>      // open(), O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
# include <string.h>     // strdup()
# include "libft.h"

int		*open_files(char *infile, char *outfile);
void	first_child(char *cmd, int in_file, int *pipefd, char **env);
void	second_child(char *cmd, int out_file, int *pipefd, char **env);
char	**div_command(char *cmd);
char	*get_full_path(char *cmd, char **env);
char	**get_path_env(char **env);
void	error_exit(int i, const char *msg, char **args_paths, char *cmd_path);
void	first_child_setup(int *pipefd, int in_file);
void	second_child_setup(int *pipefd, int out_file);

#endif