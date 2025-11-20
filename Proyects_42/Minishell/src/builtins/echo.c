/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:42:37 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 13:33:29 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_quoted(char *str, size_t len)
{
	if (str[0] == '"' && str[len - 1] == '"')
		return (1);
	if (str[0] == '\'' && str[len - 1] == '\'')
		return (1);
	return (0);
}

static void	print_arg(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (is_quoted(str, len))
		write(1, str + 1, len - 2);
	else
		printf("%s", str);
}

int	ft_builtin_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (args[i] && !ft_strncmp(args[i], "-n", 2) && args[i][2] == '\0')
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		print_arg(args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}
