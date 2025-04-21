/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_imp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:59 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:06:50 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
	if (!*lst)
		*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = content;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
}
