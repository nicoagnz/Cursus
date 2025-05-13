/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:15:44 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:40:35 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	total_len_num(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				nlen;

	nlen = total_len_num(n);
	str = malloc(nlen + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = 48;
	str[nlen] = '\0';
	while (num != 0)
	{
		str[nlen - 1] = (num % 10) + 48;
		num /= 10;
		nlen--;
	}
	return (str);
}
