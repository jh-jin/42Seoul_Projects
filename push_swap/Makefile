# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:46:40 by jjin	           #+#    #+#              #
#    Updated: 2022/11/15 20:43:57 by jjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

DIR = ./push_swap_mandatory

SRCS = $(DIR)/main.c \
		$(DIR)/libft.c \
		$(DIR)/init.c \
		$(DIR)/oper.c \
		$(DIR)/oper_utils.c \
		$(DIR)/algo.c \
		$(DIR)/algo_utils.c \
		$(DIR)/hard_sort.c \

OBJS= $(SRCS:.c=.o)

RM= rm -rf

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

all : $(NAME)

ifdef BONUS
	@make -C ./push_swap_bonus/ all
else
endif

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
bonus :
	@make BONUS=1

clean:
	@make -C ./push_swap_bonus clean
	$(RM) $(OBJS)

fclean: clean
	@make -C ./push_swap_bonus fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
