/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:05:13 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/08 09:30:52 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (((unsigned char *)s)[len] == (unsigned char)c)
			return ((unsigned char *)s + len);
		len++;
	}
	return (NULL);
}
