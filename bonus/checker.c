/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:11:22 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/11 02:15:11 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_exit(t_stack **a, t_stack **b)
{
	ft_lstclearer(a);
	if (*b)
		ft_lstclearer(b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	action(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "pa", 3))
		pusher(b, a);
	else if (!ft_strncmp(line, "pb", 3))
		pusher(a, b);
	else if (ft_strncmp(line, "ra", 3) == 0)
		rotate(a);
	else if (!ft_strncmp(line, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(line, "rr", 3))
		rotate_both(a, b);
	else if (!ft_strncmp(line, "rra", 4))
		rrotate(a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrotate(b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrotate_both(a, b);
	else if (!ft_strncmp(line, "sa", 3))
		swap(a);
	else if (!ft_strncmp(line, "sb", 3))
		swap(b);
	else if (!ft_strncmp(line, "ss", 3))
		swap_both(a, b);
	ft_putstr_fd(line, 1);
}

int	check_command(char *line)
{
	if (!ft_strncmp(line, "pa", 3) || !ft_strncmp(line, "pb", 3)
		|| ft_strncmp(line, "ra", 3) == 0 || !ft_strncmp(line, "rb", 3)
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4) || !ft_strncmp(line, "sa", 3)
		|| !ft_strncmp(line, "sb", 3) || !ft_strncmp(line, "ss", 3)
		|| !ft_strncmp(line, "rr", 3))
		return (0);
	return (-1);
}

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	char	c;
	int		i;

	line = (char *)malloc(sizeof(*line) * 4);
	if (!line)
		return ;
	i = -1;
	while (read(STDIN_FILENO, &c, 1))
	{
		if (c == '\n' || i == 3)
		{
			line[++i] = '\0';
			if (check_command(line) != 0)
			{
				free(line);
				error_exit(&stack_a, &stack_b);
			}
			i = -1;
			action(&stack_a, &stack_b, line);
		}
		else
			line[++i] = c;
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = list_create(argc, argv);
	stack_b = NULL;
	if (repeat(stack_a) || digit(argc, argv) == -1)
		error_exit(&stack_a, &stack_b);
	checker(stack_a, stack_b);
	if (is_sorted(stack_a) == 1 && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclearer(&stack_a);
	return (0);
}
