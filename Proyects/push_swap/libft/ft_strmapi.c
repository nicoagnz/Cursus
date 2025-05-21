/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:11:53 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:41:22 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*src;
	unsigned int	i;

	src = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!src)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		src[i] = (*f)(i, s[i]);
		i++;
	}
	src[i] = '\0';
	return (src);
}
