/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:03:13 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/04/21 10:04:29 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

// LIST STRUCT
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// FUNCTIONS
int		ft_wcount(const char *str);
void	check_av(int ac, char **av);
int		inva_input(char *str);
int		count_numbers(char *str, char c);
long	ft_atol(const char *nptr);
void	ft_free(void **clean);
void	ft_error(char *str, char **arg, int ac);
void	init_stack(t_stack **stack, int ac, char **av);
void	set_index(t_stack **stack);
void	check_sorted(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack);
void	free_stack(t_stack **stack);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
int		get_max_index(t_stack **stack);
int		get_min_index(t_stack **stack);
void	big_sort(t_stack **stack_a, t_stack **stack_b);

// MOVES FUNCTIONS
int		swap_stack(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		rotate_stack(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rev_rotate_stack(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		push_stack(t_stack **src, t_stack **dest);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

// LIBFT FUNCTIONS IMPORTED
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);

#endif
