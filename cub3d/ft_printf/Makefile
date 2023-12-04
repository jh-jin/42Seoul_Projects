NAME = libftprintf.a
CC = cc
FLAG = -Wall -Wextra -Werror
INCLUDES = ft_printf.h
SRCS = ft_low_x.c ft_printf.c ft_putchar.c ft_putstr.c ft_high_x.c ft_mem_address.c ft_putnbr.c ft_putunsignednbr.c
OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAG) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@make all -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar rc $@ $^

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(OBJ)
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
