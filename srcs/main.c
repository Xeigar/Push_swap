/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:02:53 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/08 00:03:22 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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