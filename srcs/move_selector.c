/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:23:11 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:40:50 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotator(t_stack **stack_a, t_stack **stack_b, t_chest stats)
{
	if (stats.positions.a_size >= stats.sizes->a_size / 2
		&& stats.positions.b_size >= stats.sizes->b_size / 2)
	{
		while (*stack_a != stats.cheapest->place
			&& *stack_b != stats.cheapest)
			cmd(stack_a, stack_b, "rrr");
	}
	else if (stats.positions.a_size <= stats.sizes->a_size / 2
		&& stats.positions.b_size <= stats.sizes->b_size / 2)
	{
		while (*stack_a != stats.cheapest->place
			&& *stack_b != stats.cheapest)
			cmd(stack_a, stack_b, "rr");
	}
}

void	single_rotator(t_stack **stack_a, t_stack **stack_b, t_chest stats)
{
	while ((*stack_a) != stats.cheapest->place)
	{
		if (stats.positions.a_size <= stats.sizes->a_size / 2)
			cmd(stack_a, stack_b, "ra");
		else
			cmd(stack_a, stack_b, "rra");
	}
	while ((*stack_b) != stats.cheapest)
	{
		if (stats.positions.b_size <= stats.sizes->b_size / 2)
			cmd(stack_a, stack_b, "rb");
		else
			cmd(stack_a, stack_b, "rrb");
	}
}

void	move_select(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest, t_stats *stats)
{
	t_stack	*temp;
	t_chest	chest;

	temp = *stack_a;
	chest.positions.a_size = 0;
	chest.positions.b_size = 0;
	chest.cheapest = cheapest;
	chest.sizes = stats;
	while (temp != cheapest->place)
	{
		chest.positions.a_size++;
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp && temp != cheapest)
	{
		chest.positions.b_size++;
		temp = temp->next;
	}
	double_rotator(stack_a, stack_b, chest);
	single_rotator(stack_a, stack_b, chest);
}
