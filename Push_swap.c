/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:42:51 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/28 18:19:13 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	l_list	*stack_a;
	l_list	*stack_b;

	stack_a = list_create(argc, argv);
	if (repeat_or_digit(argc, argv) == -1)
		exit_error(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		ft_putstr_fd("The stack is sorted\n", 2);
		return (1);
	}
	push_swap(&stack_a, &stack_b);
	l_list	*begin;
	begin = stack_a;
	while (begin)
	{
		printf("%d\n", begin->data);
		begin = begin->next;
	}
	ft_lstclearer(&stack_a);
	return (0);
}