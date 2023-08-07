/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:53:18 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:39:44 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_stack *list)
{
	while (list->next)
	{
		if (list->data > list->next->data)
			return (-1);
		list = list->next;
	}
	return (1);
}

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->data > highest->data)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->data < lowest->data)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}
