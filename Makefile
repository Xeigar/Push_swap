# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 20:01:35 by tmoutinh          #+#    #+#              #
#    Updated: 2023/08/12 22:05:01 by tmoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS = srcs/push_swap.c srcs/push_swap_utils.c srcs/moves.c srcs/move_selector.c srcs/move_calculator.c srcs/loader.c srcs/list_functions.c srcs/aux.c srcs/main.c
	
SRCS_BONUS = bonus/checker.c bonus/move_list.c srcs/push_swap.c srcs/push_swap_utils.c srcs/moves.c srcs/move_selector.c \
	srcs/move_calculator.c srcs/loader.c srcs/list_functions.c srcs/aux.c

FLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

LIBFT_PATH = libs/

LIBFT = -L $(LIBFT_PATH) -lft

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

BONUS_DIR = bonus
SRCS_DIR = srcs

# Compile bonus source files
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

# Compile regular source files
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

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

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS)
	#make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

.PHONY:all clean fclean re bonus

