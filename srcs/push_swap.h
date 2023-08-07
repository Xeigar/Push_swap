/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:43:05 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/08/07 05:02:25 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libs/libft.h"
# include <stdio.h>

typedef struct f_list
{
	long			data;
	int				order;
	int				price;
	struct f_list	*place;
	struct f_list	*next;
}	t_stack;

typedef struct d_list
{
	int	a_size;
	int	b_size;
}	t_stats;

typedef struct p_list
{
	t_stats	*sizes;
	t_stats	positions;
	t_stack	*cheapest;
}	t_chest;

/*Aux functions*/
long	ft_long_atoi(const char *nptr);
void	exit_error(t_stack *current);
int		repeat(t_stack *stack_a);
int		digit(int argc, char **argv);
long	ft_long_atoi(const char *nptr);
void	ordering(t_stack **stack_a);
void	b_filler(t_stack	**stack_a, t_stack **stack_b);
void	finalizer(t_stack **stack_a, int size);
void	occur(t_stack **stack, int middle_value, int *i, int *j);
void	find_next(t_stack **stack, int middle_value);
t_stack	*get_position(t_stack *stack_a, t_stack *value);
void	move_select(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest, t_stats *stats);
void	calculator(t_stack *stack_a, t_stack *stack_b,
			t_stack **cheapest, t_stats *stats);
void	opposite(t_stack *temp, t_stats *stats, int place, int position);
void	single_rotator(t_stack **stack_a, t_stack **stack_b, t_chest stats);
void	double_rotator(t_stack **stack_a, t_stack **stack_b, t_chest stats);
/*List related functions*/
t_stack	*list_create(int argc, char **argv);
void	ft_lstclearer(t_stack **lst);
void	ft_lstadd(t_stack **lst, t_stack *new);
t_stack	*ft_newnode(int content);
int		list_size(t_stack *list);
t_stack	*find_highest(t_stack *stack_a);
t_stack	*find_lowest(t_stack *stack);
/*Sorting functions*/
int		is_sorted(t_stack *list);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
void	big_sort(t_stack **stack_a, t_stack **stack_b);
/*Move Functions*/
void	swap(t_stack **list);
void	rotate(t_stack	**list);
void	rrotate(t_stack	**list);
void	push(t_stack **src, t_stack **dest, char *stack);
void	cmd(t_stack **stack_a, t_stack **stack_b, char *move);

#endif