/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:25:38 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/05 18:27:32 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclearer(l_list **lst)
{
	l_list	*next;
	l_list	*current;

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

void	ft_lstadd(l_list **lst, l_list *new)
{
	l_list	*current;

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

l_list	*ft_newnode(int content)
{
	l_list	*p;

	p = (l_list *)malloc(sizeof(*p));
	if (!p)
		return (NULL);
	p->data = content;
	p->order = -1;
	p->price = -1;
	p->next = NULL;
	p->place = NULL;
	return (p);
}

l_list	*list_create(int argc, char **argv)
{
	int			i;
	long		num;
	l_list	*current;
	l_list	*tracker;

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

int	list_size(l_list *list)
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