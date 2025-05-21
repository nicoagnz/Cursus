/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:51:19 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 11:07:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**set_stack(void)
{
	t_stack	**stack;

	stack = (t_stack **)malloc(sizeof(t_stack **));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

int	ft_wcount(const char *str)
{
	int	w_count;

	if (!str)
		return (0);
	w_count = 0;
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		if (*str)
			w_count++;
		while (*str != ' ' && *str)
			str++;
	}
	return (w_count);
}

void	check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stack		**stack_a;
	t_stack		**stack_b;

	if (ac < 2 || (ac == 2 && ft_wcount(av[1]) <= 1))
		return (-1);
	check_av(ac, av);
	stack_a = set_stack();
	stack_b = set_stack();
	init_stack(stack_a, ac, av);
	check_sorted(stack_a, stack_b);
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
	