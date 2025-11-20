/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:13:49 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:55:09 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*init_temp_s1(char *s1)
{
	char	*temp_s1;

	if (s1)
		return (s1);
	temp_s1 = (char *)malloc(sizeof(char) * 1);
	if (!temp_s1)
		return (NULL);
	temp_s1[0] = '\0';
	return (temp_s1);
}

static char	*allocate_str(char *temp_s1, char *s2, char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(temp_s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		if (!s1)
			free(temp_s1);
		return (NULL);
	}
	return (str);
}

static void	copy_strings(char *str, char *temp_s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (temp_s1[i])
		str[j++] = temp_s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*temp_s1;

	temp_s1 = init_temp_s1(s1);
	if (!temp_s1)
		return (NULL);
	if (!s2)
	{
		if (!s1)
			free(temp_s1);
		return (NULL);
	}
	str = allocate_str(temp_s1, s2, s1);
	if (!str)
		return (NULL);
	copy_strings(str, temp_s1, s2);
	if (!s1)
		free(temp_s1);
	return (str);
}
