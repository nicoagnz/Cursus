/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:11:34 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:03:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	int	max;

	max = get_max_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->index == max)
	{
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else if ((*stack_a)->next->index == max)
	{
		sa(stack_a);
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else
		sa(stack_a);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->next->next->next->index == min)
		rra(stack_a);
	while ((*stack_a)->index != min)
		ra(stack_a);
	if ((*stack_a)->index == min)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->next->next->next->next->index == min)
		rra(stack_a);
	while ((*stack_a)->index != min)
		ra(stack_a);
	if ((*stack_a)->index == min)
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
