/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:58:46 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:41:53 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack *current)
{
	ft_lstclearer(&current);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*highest;

	highest = find_highest(*stack_a);
	if (*stack_a == highest)
		cmd(stack_a, stack_b, "ra");
	else if ((*stack_a)->next == highest)
		cmd(stack_a, stack_b, "rra");
	if ((*stack_a)->data > (*stack_a)->next->data)
		cmd(stack_a, stack_b, "sa");
}

void	finalizer(t_stack **stack_a, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp->order != 1)
	{
		temp = temp->next;
		i++;
	}
	if (i < size / 2)
	{
		while ((*stack_a)->order != 1)
			cmd(stack_a, NULL, "ra");
	}
	else
	{
		while ((*stack_a)->order != 1)
			cmd(stack_a, NULL, "rra");
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stats	stats;

	ordering(stack_a);
	b_filler(stack_a, stack_b);
	small_sort(stack_a, stack_b);
	while (*stack_b)
	{
		stats.a_size = list_size(*stack_a);
		stats.b_size = list_size(*stack_b);
		cheapest = NULL;
		calculator(*stack_a, *stack_b, &cheapest, &stats);
		move_select(stack_a, stack_b, cheapest, &stats);
		push(stack_b, stack_a, "pa");
	}
	finalizer(stack_a, stats.a_size);
}
