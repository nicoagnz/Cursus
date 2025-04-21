/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:54:25 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 09:13:57 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stack_a)
{
	int	max;
	int	max_bits;

	max = get_max_index(stack_a);
	max_bits = 0;
	while (max >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	sort_b(t_stack **stack_a, t_stack **stack_b, int max_bits, int bit)
{
	int	size;

	size = ft_lstsize(*stack_b);
	while (size-- && !is_sorted(stack_a) && bit <= max_bits)
	{
		if (((*stack_b)->index >> bit & 1) == 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	if (is_sorted(stack_a))
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	bit;
	int	size;

	max_bits = get_max_bits(stack_a);
	bit = 0;
	while (bit <= max_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size-- && !is_sorted(stack_a))
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		bit++;
		sort_b(stack_a, stack_b, max_bits, bit);
	}
	while (ft_lstsize(*stack_b))
		pa(stack_a, stack_b);
}
