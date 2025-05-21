/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:57:51 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:03:15 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	init_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	int		i;
	char	**arg;

	i = 0;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i++;
		arg = av;
	}
	while (arg[i])
	{
		new = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	set_index(stack);
	if (ac == 2)
		ft_free((void **)arg);
}
