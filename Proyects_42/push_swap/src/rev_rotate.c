/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:54:04 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:01:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(*stack);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (rev_rotate_stack(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (rev_rotate_stack(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	if (rev_rotate_stack(stack_a) == -1 || rev_rotate_stack(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (0);
}
