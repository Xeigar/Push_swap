/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:26:15 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:40:32 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_position(t_stack *stack_a, t_stack *value)
{
	t_stack	*rec;
	t_stack	*temp;

	rec = stack_a;
	temp = stack_a;
	while (temp)
	{
		if (rec->order < temp->order)
			rec = temp;
		temp = temp->next;
	}
	temp = stack_a;
	while (temp)
	{
		if (rec->order > temp->order && temp->order > value->order)
			rec = temp;
		temp = temp->next;
	}
	return (rec);
}

void	opposite(t_stack *temp, t_stats *stats, int place, int position)
{
	if (place > stats->a_size / 2)
	{
		if ((stats->a_size - place) > position)
			temp->price = (stats->a_size - place);
		else
			temp->price = position;
	}
	else
	{
		if ((stats->b_size - position) > place)
			temp->price = (stats->b_size - position);
		else
			temp->price = place;
	}	
}

void	price_selector(t_stack *temp, t_stats *stats, int place, int position)
{
	if (position <= stats->b_size / 2 && place <= stats->a_size / 2)
	{
		if (place > position)
			temp->price = place;
		else
			temp->price = position;
	}
	else if (position > stats->b_size / 2 && place > stats->a_size / 2)
	{
		if ((stats->a_size - place) > (stats->b_size - position))
			temp->price = (stats->a_size - place);
		else
			temp->price = (stats->b_size - position);
	}
	else
		opposite(temp, stats, place, position);
}

void	calculator(t_stack *stack_a, t_stack *stack_b,
	t_stack **cheapest, t_stats *stats)
{
	t_stack	*temp;
	t_stack	*runner;
	int		position;
	int		place;

	temp = stack_b;
	position = 0;
	while (temp)
	{
		place = 0;
		runner = stack_a;
		temp->place = get_position(stack_a, temp);
		while (temp->place != runner)
		{
			place++;
			runner = runner->next;
		}
		price_selector(temp, stats, place, position);
		if (!*cheapest || (*cheapest)->price > temp->price)
			*cheapest = temp;
		temp = temp->next;
		position++;
	}
}
