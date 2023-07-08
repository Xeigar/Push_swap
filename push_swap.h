/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:43:05 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/07/04 11:41:54 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

typedef struct f_list
{
	int		data;
	int		order;
	struct f_list	*next;
}	l_list;

/*Aux functions*/
long	ft_long_atoi(const char *nptr);
void	exit_error(l_list *current);
int	repeat_or_digit(int argc, char **argv);
/*List related functions*/
l_list	*list_create(int argc, char **argv);
void	ft_lstclearer(l_list **lst);
void	ft_lstadd(l_list **lst, l_list *new);
l_list	*ft_newnode(int content);
int		list_size(l_list *list);
l_list	*find_highest(l_list *stack_a);
/*Sorting functions*/
int		is_sorted(l_list *list);
void	push_swap(l_list **stack_a, l_list **stack_b);
void	small_sort(l_list **stack_a, l_list **stack_b);
/*Move Functions*/
void	swap(l_list **list);
void	rotate(l_list	**list);
void	rrotate(l_list	**list);
void	push(l_list **src, l_list **dest, char *stack);
void	cmd(l_list **stack_a, l_list **stack_b, char *move);

#endif