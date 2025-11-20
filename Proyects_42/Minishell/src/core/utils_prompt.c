/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:09:44 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:07 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	copy_str(char *dest, const char *src, int pos)
{
	int	i;

	i = 0;
	while (src[i])
		dest[pos++] = src[i++];
	return (pos);
}

void	build_prompt(char *prompt, char *username, char *cwd)
{
	int	i;

	i = 0;
	i = copy_str(prompt, BPURPLE, i);
	i = copy_str(prompt, username, i);
	i = copy_str(prompt, "@minishell~", i);
	i = copy_str(prompt, YELLOW, i);
	i = copy_str(prompt, cwd, i);
	i = copy_str(prompt, "->", i);
	i = copy_str(prompt, RESET, i);
	prompt[i] = '\0';
}
