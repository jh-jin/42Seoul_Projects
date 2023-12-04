# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 22:23:21 by jjin              #+#    #+#              #
#    Updated: 2022/11/15 23:38:38 by jjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

B_SRCS = 	init.c \
			libft.c \
			main_bonus.c \
			oper.c \
			oper_double.c\
			oper_utils.c \
			get_next_line.c \
			get_next_line_utils.c\
			checker.c

B_OBJS = $(B_SRCS:.c=.o)

RM = rm -rf

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^
all : $(NAME)

$(NAME) : $(B_OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	$(RM) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re