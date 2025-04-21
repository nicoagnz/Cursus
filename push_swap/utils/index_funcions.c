/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:02:15 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:10:59 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack **stack)
{
	t_stack	*temp;
	int		max;

	temp = *stack;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	get_min_index(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		first_time;

	head = *stack;
	min = NULL;
	first_time = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (first_time == 0
					|| head->value < min->value))
			{
				min = head;
				first_time = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	set_index(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
