/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:14:04 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/11 12:41:03 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*new_object;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	new_list = NULL;
// 	while (lst)
// 	{
// 		new_object = ft_lstnew(f(lst -> content));
// 		if (!new_object)
// 		{
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new_list, new_object);
// 		lst = lst -> next;
// 	}
// 	return (new_list);
// }
