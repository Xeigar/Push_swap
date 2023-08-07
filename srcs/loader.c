/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:14:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:40:14 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*This function orders the elements of the list from 1-n and 
assigns this number to the order variable in the stack*/
void	ordering(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*next;
	t_stack	*highest;
	int		i;

	i = 0;
	highest = find_highest(*stack_a);
	highest->order = list_size(*stack_a);
	while (++i < list_size(*stack_a))
	{
		temp = *stack_a;
		next = find_lowest(*stack_a);
		while (temp)
		{
			if (temp->order == -1 && temp->data > next->data)
				next = temp;
			temp = temp->next;
		}
		next->order = highest->order - 1;
		highest = next;
	}
	temp = *stack_a;
}

void	occur(t_stack **stack, int middle_value, int *i, int *j)
{
	t_stack	*temp;
	int		first;

	temp = *stack;
	first = 0;
	while (temp)
	{
		if ((first == 0) && temp->order > middle_value)
			*i = *i + 1;
		else
			first = 1;
		if (temp->order <= middle_value)
			*j = 1;
		temp = temp->next;
		*j = *j + 1;
	}
}

void	find_next(t_stack **stack, int middle_value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	occur(stack, middle_value, &i, &j);
	if (i <= j)
		cmd(stack, NULL, "ra");
	else
		cmd(stack, NULL, "rra");
}

/*Optimize the pushing to B part of the function by working with Max
and Min, as well as count the number of rrb and rb*/
void	b_filler(t_stack	**stack_a, t_stack **stack_b)
{
	int	counter;
	int	middle_value;

	middle_value = list_size(*stack_a) / 2;
	while (list_size(*stack_a) > 2)
	{
		counter = list_size(*stack_a) / 2;
		while (counter > 0)
		{
			if (list_size(*stack_a) == 3)
				small_sort(stack_a, NULL);
			if (is_sorted(*stack_a) == 1)
				return ;
			if ((*stack_a)->order <= middle_value)
			{
				push(stack_a, stack_b, "pb");
				counter--;
			}
			else
				find_next(stack_a, middle_value);
		}
		middle_value = middle_value + list_size(*stack_a) / 2;
	}
}
