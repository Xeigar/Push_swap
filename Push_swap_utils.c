/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:58:46 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/07/27 19:19:36 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(l_list *current)
{
	ft_lstclearer(&current);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

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

void	small_sort(l_list **stack_a, l_list **stack_b)
{
	l_list	*highest;

	highest = find_highest(*stack_a);
	if (*stack_a == highest)
		cmd(stack_a, stack_b, "ra");
	else if ((*stack_a)->next == highest)
		cmd(stack_a, stack_b, "rra");
	if ((*stack_a)->data > (*stack_a)->next->data)
		cmd(stack_a, stack_b, "sa");
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

void	chaser(l_list **stack_a, l_list **stack_b, l_list *comp)
{
	l_list	*temp;
	int		i;

 	temp = *stack_b;
	i = 0;
	while (temp != comp)
	{
		temp = temp->next;
		i++;
	}
	if (i < list_size(*stack_b))
		cmd(stack_a, stack_b, "rrb");
	else
		cmd(stack_a, stack_b, "rb");
}

void	occur(l_list **stack, int middle_value, int *i, int *j)
{
	l_list	*temp;
	int		first;

	temp = *stack;
	first = 0;
	while (temp)
	{
		if ((first == 0) && temp->order > middle_value)
			i++;
		else
			first = 1;
		if (temp->order < middle_value)
			j = 0;
		temp = temp->next;
		j++;
		printf("%d, %d\n", *i, *j);
	}
}

void	find_next(l_list **stack, int middle_value)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	occur(stack, middle_value, &i, &j);
	printf("%d, %d\n", i, j);
	if (i <= (list_size(*stack) - j + 1))
		cmd(stack, NULL, "ra");
	else
		cmd(stack, NULL, "rra");
}

/*Optimize the pushing to B part of the function by working with Max
and Min, as well as count the number of rrb and rb*/
void	b_filler(l_list	**stack_a, l_list **stack_b)
{
	int	counter;
	int middle_value;
	
	middle_value = list_size(*stack_a) / 2; // 5 
	while (list_size(*stack_a) > 2)
	{
		counter = list_size(*stack_a) / 2; // 4
		while (counter > 0)
		{
			//printf("comparacao %d <= %d\n", (*stack_a)->order, middle_value);
			//printf("%d\n", counter);
			if ((*stack_a)->order <= middle_value)
			{
				push(stack_a, stack_b, "pb");
				counter--;
			}
			else
			{
				find_next(stack_a, middle_value);
			}
		}
		middle_value = middle_value + list_size(*stack_a) / 2;
	}
}

int	last_check(l_list **stack_a, int order)
{
	l_list	*temp;

	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	if (temp->order > order)
		return (1);
	return (0);
}

void	finalizer(l_list **stack_a)
{
	l_list	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp->order != 1)
	{
		temp = temp->next;
		i++;
	}
	if (i < list_size(*stack_a) / 2)
	{
		while ((*stack_a)->order != 1)
			cmd(stack_a, NULL, "ra");
	}
	else
	{
		while ((*stack_a)->order != 1)
			cmd(stack_a, NULL, "rra");
	}
}

char	*get_cmd(l_list *stack, l_list *find) //Need to implement on case_select!
{
	int	i;

	i = 0;
	while (stack != find)
	{
		i++;
		stack = stack->next;
	}
	if (i < list_size(stack))
		return ("ra");
	else
		return ("rra");
}

void	case_select(l_list **stack_a, l_list **stack_b)
{
	l_list	*low;
	l_list	*high;

	low = find_lowest(*stack_a);
	high = find_highest (*stack_a);
	if ((*stack_b)->order > high->order)
	{	
		//printf("Choice 1\n");
		while ((*stack_a) != low)
			cmd(stack_a, stack_b, "ra");
		push(stack_b, stack_a, "pa");
	}
	else if (low->order > (*stack_b)->order)
	{
		//printf("Choice 2\n");
		
		while ((*stack_a)->order != low->order)
			cmd(stack_a, stack_b, "ra");
		push(stack_b, stack_a, "pa");
	}
	else
	{
		//printf("Choice 3\n");
		while ((*stack_a)->order < (*stack_b)->order || last_check(stack_a, (*stack_b)->order) != 0)
			cmd(stack_a, stack_b, "ra");
		push(stack_b, stack_a, "pa");
	}
}

void	big_sort(l_list **stack_a, l_list **stack_b)
{
	ordering(stack_a);
	//push(stack_a, stack_b, "pb");
	b_filler(stack_a, stack_b);
	small_sort(stack_a, stack_b);
	//printf(" -----------\ndone small sort\n -----------\n");
	while(*stack_b)
	//Printer
	{
		
	// 	l_list	*begin;
	// begin = *stack_a;
	// printf("________________________\n");
	// while (begin)
	// {
	// 	printf("a = %d\n", begin->data);
	// 	printf("a->order = %d\n", begin->order);
	// 	begin = begin->next;
	// }
	// begin = *stack_b;
	// while (begin)
	// {
	// 	printf("b = %d\n", begin->data);
	// 	begin = begin->next;
	// }
	// printf("________________________\n");
	//End Printer
		case_select(stack_a, stack_b);
	}
	finalizer(stack_a);
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
