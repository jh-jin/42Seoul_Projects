# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 23:11:11 by jjin              #+#    #+#              #
#    Updated: 2022/11/02 16:53:12 by jjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/, \
 ft_split.c\
 get_next_line_utils.c\
 get_next_line.c\
 hooks.c\
 init.c\
 map_check.c\
 map_io.c\
 utils.c\
 so_long.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	make -C ./mlx/
	$(CC) $(CFLAG) $(MLX) -o $@ $^
	
clean :
	make -C ./mlx/ clean
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re