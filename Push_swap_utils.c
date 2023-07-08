/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:58:46 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/07/07 00:55:09 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(l_list *current)
{
	ft_lstclearer(&current);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	repeat_or_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (-1);
		}
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
	if (*nptr >= '0' && *nptr <= '9')
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			i = i * 10 + (*nptr - 48);
			nptr++;
		}
	}
	else
		return (-2147483649);
	return (i * neg);
}

int	is_sorted(l_list *list)
{
	l_list	*first;

	first = list;
	while (list->next)
	{
		if (list->data > list->next->data)
			return (-1);
		list = list->next;
	}
	ft_lstclearer(&first);
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


void	small_sort(l_list **stack_a, l_list **stack_b)
{
	l_list	*highest;

	highest = find_highest(*stack_a);
	if (*stack_a == highest)
		cmd(stack_a, stack_b, "ra");
	if ((*stack_a)->data > (*stack_a)->next->data)
		cmd(stack_a, stack_b, "sa");
	else
		cmd(stack_a, stack_b, "rra");
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

/*This function orders the elements of the list from 1-n and 
assigns this number to the order variable in the stack*/
void	ordering(l_list **stack_a)
{
	l_list	*temp;
	l_list	*next;
	l_list	*highest;
	int		i;

	i = 0;
	highest = find_highest(*stack_a);
	highest->order = list_size(*stack_a);
	while(++i < list_size(*stack_a))
	{
		temp = *stack_a;
		next = find_lowest(*stack_a);
		while(temp)
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

/**This function finds the position of the closest number of the partition
and sends it to stack_b with the least amount of move**/
void	finder_pusher(l_list **stack_a, l_list **stack_b, int partition)
{
	l_list	*temp;
	int		a;
	int		b;

	temp = *stack_a;
	a = 0;
	b = 0;
	while (temp)
	{
		if (a == 0 && temp->order <= partition)	
			a = temp->order;
		if (temp->order < partition)
			b = temp->order;
		temp = temp->next;
	}
	if (a <= (list_size(*stack_a) - b))
	{
		while ((*stack_a)->order != a)
			cmd(stack_a, stack_b, "rra");
	}
	else
	{
		while ((*stack_a)->order != b)
			cmd(stack_a, stack_b, "ra");
	}
	push(stack_a, stack_b, "pb");
}

void	big_sort(l_list **stack_a, l_list **stack_b)
{
	//l_list	*temp;
	int		partition;
	int		counter;
	int		runner;

	//temp = *stack_a;
	ordering(stack_a);
	if (list_size(*stack_a) <= 100)
		partition = 4;
	else
		partition = 8;
	runner = 0;
	while (++runner < partition)
	{
		counter = -1;
		printf("%d\n", list_size(*stack_a)/ partition);
		while (++counter < ((list_size(*stack_a)/ partition) * runner))
			finder_pusher(stack_a, stack_b, list_size(*stack_a)/ partition); /*Need to
			to revise the partition variable it is not working in the finder_pusher*/
	}
}

void	push_swap(l_list **stack_a, l_list **stack_b)
{
	if (list_size(*stack_a) == 2)
		cmd(stack_a, stack_b, "sa");
	else if (list_size(*stack_a) == 3)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}
