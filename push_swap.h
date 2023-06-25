/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:43:05 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/25 18:39:57 by tmoutinh         ###   ########.fr       */
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
	int		pos;
	struct f_list	*next;
}	l_list;

long	ft_long_atoi(const char *nptr);
void	del(void *lst_content);
void	exit_error(l_list *current);
int	repeat_or_digit(int argc, char **argv);
l_list	*list_create(int argc, char **argv);


#endif