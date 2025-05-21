/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:44:46 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:41:18 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
