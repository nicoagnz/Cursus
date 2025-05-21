/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:41:45 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/05/06 13:00:00 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*delete;
	t_list	*temp;

	delete = *lst;
	if (!delete)
		return ;
	while (delete)
	{
		temp = delete -> next;
		del(delete -> content);
		free(delete);
		delete = temp;
	}
	*lst = NULL;
}
