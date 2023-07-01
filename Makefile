# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 20:01:35 by tmoutinh          #+#    #+#              #
#    Updated: 2023/06/29 16:49:47 by tmoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -Wall -Werror -Wextra -g Push_swap.c Push_swap_utils.c List_functions.c moves.c libft.a