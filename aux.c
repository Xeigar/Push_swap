/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:53:18 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/01 19:54:55 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeat_or_digit(int argc, char **argv, l_list *stack_a)
{
	int	i;
	int	k;
	l_list	*pos;
	l_list	*runner;

	i = 0;
	pos = stack_a;
	while (pos)
	{
		runner = stack_a;
		while (runner)
		{
			if (runner->data == pos->data && 
				runner != pos)
				return (-1);
			runner = runner->next;
		}
		pos = pos->next;
	}
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
		{
			if (ft_isdigit(argv[i][k]) ==  0
				&& (argv[i][k] != '+' && argv[i][k] != '-'))
				return (-1);
		}
	}
	return (0);
}

long	ft_long_atoi(const char *nptr)
{
	long	i;
	long	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (-2147483649);
	while (*nptr)
	{
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (-2147483649);
		i = i * 10 + (*nptr - 48);
		nptr++;
	}
	return (i * neg);
}

int	is_sorted(l_list *list)
{
	while (list->next)
	{
		if (list->data > list->next->data)
			return (-1);
		list = list->next;
	}
	return (1);
}

l_list	*find_highest(l_list *stack)
{
	l_list	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->data > highest->data)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

l_list	*find_lowest(l_list *stack)
{
	l_list	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->data < lowest->data)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}
