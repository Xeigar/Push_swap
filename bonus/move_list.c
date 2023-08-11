/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:22:01 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/10 14:30:43 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrotate_both(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	pusher(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}
