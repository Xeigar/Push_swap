/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:45:27 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/29 18:54:40 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(l_list **list, char *stack)
{
	l_list *temp;

	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = (*list);
	(*list) = temp;
	
	ft_putstr_fd(stack, 1);
	ft_putstr_fd("\n", 1);
}

void	rotate(l_list	**list, char *stack)
{
	l_list	*temp;
	l_list	*last;

	temp = *list;
	*list = (*list)->next;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = temp;	
	temp->next = NULL;
	
	ft_putstr_fd(stack, 1);
	ft_putstr_fd("\n", 1);
}

void	rrotate(l_list	**list, char *stack)
{
	l_list	*last;

	last = *list;
	while (last->next->next)
		last = last->next;
	last->next->next = *list;
	(*list) = last->next;
	last->next = NULL;
	
	ft_putstr_fd(stack, 1);
	ft_putstr_fd("\n", 1);
}

void	push(l_list **list_a, l_list **list_b, char *stack)
{
	
}