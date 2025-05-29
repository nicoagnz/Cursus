/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:26:06 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/08 09:31:00 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	len = 0;
	d = (char *)dest;
	s = (char *)src;
	while (len < n)
	{
		d[len] = s[len];
		len++;
	}
	return (dest);
}
