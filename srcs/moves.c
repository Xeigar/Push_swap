/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:45:27 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:41:36 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*temp;

	if (!(*list)->next)
		return ;
	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = (*list);
	(*list) = temp;
}

void	rotate(t_stack	**list)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*list)->next)
		return ;
	temp = *list;
	*list = (*list)->next;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	rrotate(t_stack	**list)
{
	t_stack	*last;

	if (!(*list)->next)
		return ;
	last = *list;
	while (last->next->next)
		last = last->next;
	last->next->next = *list;
	(*list) = last->next;
	last->next = NULL;
}

void	push(t_stack **src, t_stack **dest, char *stack)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	ft_putstr_fd(stack, 1);
	ft_putstr_fd("\n", 1);
}

void	cmd(t_stack **stack_a, t_stack **stack_b, char *move)
{
	void	(*func)(t_stack **);

	if (move[0] == 's')
		func = &swap;
	else if (move[0] == 'r' && move[2])
		func = &rrotate;
	else
		func = &rotate;
	if (move[1] == 'a' || move[2] == 'a')
		func(stack_a);
	if (move[1] == 'b' || move[2] == 'b')
		func(stack_b);
	if (move[1] == 's' || (move[0] == 'r' && move[1] == 'r' && !move[2])
		|| move[2] == 'r')
	{
		func(stack_a);
		func(stack_b);
	}
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
}
