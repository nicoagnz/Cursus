/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:44:46 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/01/08 09:31:46 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size == 0)
	{
		while (src[len])
			len++;
		return (len);
	}
	while (len < size - 1 && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	if (len < size)
		dest[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
