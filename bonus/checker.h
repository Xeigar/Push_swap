/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:48:04 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/12 13:06:25 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../srcs/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b);
void	rrotate_both(t_stack **a, t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
void	pusher(t_stack **src, t_stack **dest);
void	error_exit(t_stack **a, t_stack **b);
void	action(t_stack **a, t_stack **b, char *line);
void	checker(t_stack *stack_a, t_stack *stack_b);
int		main(int argc, char **argv);

#endif