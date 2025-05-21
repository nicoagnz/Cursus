/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:33:10 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:06:05 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*head_dst;
	t_stack	*head_src;
	t_stack	*temp;

	if (ft_lstsize(*src) == 0)
		return (-1);
	head_dst = *dest;
	head_src = *src;
	temp = head_src;
	head_src = head_src->next;
	*src = head_src;
	if (!head_dst)
	{
		head_dst = temp;
		head_dst->next = NULL;
		*dest = head_dst;
	}
	else
	{
		temp->next = head_dst;
		*dest = temp;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push_stack(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push_stack(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
