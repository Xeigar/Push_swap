/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:42:51 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 04:50:42 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (list_size(*stack_a) == 2)
		cmd(stack_a, stack_b, "sa");
	else if (list_size(*stack_a) == 3)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	repeat(t_stack *stack_a)
{
	t_stack	*pos;
	t_stack	*runner;

	if (!stack_a)
		return (-1);
	pos = stack_a;
	while (pos)
	{
		runner = stack_a;
		while (runner)
		{
			if (runner->data == pos->data
				&& runner != pos)
				return (-1);
			runner = runner->next;
		}
		pos = pos->next;
	}
	return (0);
}

int	digit(int argc, char **argv)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
		{
			if (ft_isdigit(argv[i][k]) == 0
				&& (argv[i][k] != '+' && argv[i][k] != '-'))
				return (-1);
		}
	}
	return (0);
}

/*Check if it is ok to leave message*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = list_create(argc, argv);
	stack_b = NULL;
	if (repeat(stack_a) || digit(argc, argv) == -1)
		exit_error(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		ft_putstr_fd("The stack is sorted\n", 2);
		ft_lstclearer(&stack_a);
		return (1);
	}
	push_swap(&stack_a, &stack_b);
	ft_lstclearer(&stack_a);
	return (0);
}
