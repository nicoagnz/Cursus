/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:44:31 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/08 09:30:56 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	len;
	char	*p1;
	char	*p2;

	len = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	while (len < n)
	{
		if (p1[len] != p2[len])
			return (((unsigned char *)p1)[len] - ((unsigned char *)p2)[len]);
		len++;
	}
	return (0);
}
