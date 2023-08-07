/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:25:38 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:40:01 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclearer(t_stack **lst)
{
	t_stack	*next;
	t_stack	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = current;
}

void	ft_lstadd(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!lst || !new)
		return ;
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_stack	*ft_newnode(int content)
{
	t_stack	*p;

	p = (t_stack *)malloc(sizeof(*p));
	if (!p)
		return (NULL);
	p->data = content;
	p->order = -1;
	p->price = -1;
	p->next = NULL;
	p->place = NULL;
	return (p);
}

t_stack	*list_create(int argc, char **argv)
{
	int		i;
	long	num;
	t_stack	*current;
	t_stack	*tracker;

	i = 0;
	current = NULL;
	while (++i < argc)
	{
		num = ft_long_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			exit_error(current);
		tracker = ft_newnode(num);
		ft_lstadd(&current, tracker);
	}
	return (current);
}

int	list_size(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
