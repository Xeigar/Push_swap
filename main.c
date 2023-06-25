/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:42:51 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/25 18:40:23 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main (int argc, char **argv)
{
	l_list	*list;

	list = list_create(argc, argv);
	if (repeat_or_digit(argc, argv) == -1)
		exit_error(list);
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);
}