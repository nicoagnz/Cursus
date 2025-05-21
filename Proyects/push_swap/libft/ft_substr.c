/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:11:35 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:41:32 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	tsize;
	char	*p;

	i = 0;
	if (start > (unsigned)ft_strlen(s))
		return (ft_strdup(""));
	tsize = ft_strlen(s) - start;
	if (len > tsize)
		len = tsize;
	p = malloc(len + 1);
	if (p == 0)
		return (NULL);
	while (len > i)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
