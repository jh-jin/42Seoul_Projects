# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 20:01:32 by jjin              #+#    #+#              #
#    Updated: 2022/07/07 20:32:36 by jjin             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= includes
LIBFT		= libft
SRC_DIR		= srcs/
OBJ_DIR		= objs/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -rf
AR			= ar rcs

SRC_FILES	=	ft_printf ft_print_char ft_print_dec\
			ft_print_hex ft_print_ptr ft_print_str ft_print_unsigned
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a
			
re:			fclean all

.PHONY:		all clean fclean re