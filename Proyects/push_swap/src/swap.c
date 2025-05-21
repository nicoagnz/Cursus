/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:05 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/17 11:14:15 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		temp_value;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		return (-1);
	temp_value = head->value;
	temp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp_value;
	next->index = temp_index;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (swap_stack(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap_stack(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	if (swap_stack(stack_a) == -1 || swap_stack(stack_b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
