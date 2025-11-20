/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:42:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/20 10:41:14 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	g_signal_exit_code = 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	if (rl_line_buffer && rl_line_buffer[0] != '\0')
	{
		write(1, "\nquit\n", 6);
		exit(131);
	}
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_sigtstp(int sig)
{
	(void)sig;
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigtstp);
}
