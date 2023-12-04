# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 20:56:49 by jjin              #+#    #+#              #
#    Updated: 2022/10/06 21:11:30 by jjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = utils.c
OBJ=$(SRC:.c=.o)
HEADER	= minitalk.h
server = server 
client = client
all: $(server) $(client)

$(server):$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) server.c $(OBJ) -o $(server)
$(client):$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) client.c $(OBJ) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(client) $(server)
re: fclean all
