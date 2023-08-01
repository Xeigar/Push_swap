# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 20:01:35 by tmoutinh          #+#    #+#              #
#    Updated: 2023/08/01 19:54:27 by tmoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -Wall -Werror -Wextra -g Push_swap.c Push_swap_utils.c List_functions.c moves.c aux.c libft.a -o push_swap
	rm -r push_swap_visualizer/push_swap
	cp push_swap push_swap_visualizer/push_swap