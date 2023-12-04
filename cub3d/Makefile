NAME = cub3D

BONUS_NAME = checker

SRCS = ./src/main.c \
	./src/ceiling.c \
	./src/check_news.c \
	./src/draw.c \
	./src/floor.c \
	./src/get_next_line.c \
	./src/init.c \
	./src/key.c \
	./src/move.c \
	./src/parsing.c \
	./src/utility.c \
	./src/utility2.c \
	./src/valid_map.c \
	./src/vec.c \

# BONUS_SRCS =

HEADER = ./cub3d.h

# BONUS_HEADER =

CC = cc

FLAG = -Wall -Wextra -Werror -g -fsanitize=address

CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

RM = rm -f

LIBS = -L ./ft_printf -lftprintf

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS_SRCS:.c=.o)

%.o:%.c
	$(CC) $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
			make all -C ./ft_printf
			$(CC) $(FLAG) $(CLIB) $(LIBS) $(SRCS) -o $(NAME)
			install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

bonus: $(OBJ_BONUS) $(BONUS_HEADER)
			make all -C ./ft_printf
			$(CC) $(FLAG) $(OBJ_BONUS) -o $(BONUS_NAME) $(LIBS)


all: $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(BONUS_OBJ)
			@make fclean -C ./ft_printf

fclean: clean
		$(RM) $(NAME) $(OBJ)
		$(RM) $(BONUS_NAME) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean fclean re
