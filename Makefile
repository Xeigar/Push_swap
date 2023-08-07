# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 20:01:35 by tmoutinh          #+#    #+#              #
#    Updated: 2023/08/07 05:04:41 by tmoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = pipex_bonus

SRCS = srcs/push_swap.c srcs/push_swap_utils.c srcs/moves.c srcs/move_selector.c \
	srcs/move_calculator.c srcs/loader.c srcs/list_functions.c srcs/aux.c
	
SRCS_BONUS =

FLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

LIBFT_PATH = libs/

LIBFT = -L $(LIBFT_PATH) -lft

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o:%.c
		${CC} ${FLAGS} -c $< -o srcs/$(@F)

$(NAME): $(OBJS)
	#make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)


all: $(NAME)

clean:
	#make -C ${LIBFT_PATH} clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	#make -C ${LIBFT_PATH} fclean
	${RM} ${NAME}
	$(RM) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

.PHONY:all clean fclean re bonus

