/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:21:05 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:40:22 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	else
	{
		while (i < (nmemb * size))
		{
			p[i] = 0;
			i++;
		}
	}
	return (p);
}
