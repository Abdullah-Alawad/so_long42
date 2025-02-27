# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalawad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 14:52:08 by aalawad           #+#    #+#              #
#    Updated: 2025/02/02 14:52:10 by aalawad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_checker.c ft_errors.c ft_set_game.c ft_map_parse.c \
		ft_checker_map.c ft_copy_map.c ft_check_solvability.c ft_init_game.c \
		ft_handle_keys.c

MAIN_SRC = so_long.c

OBJS = ${SRCS:.c=.o}

MAIN_OBJ = so_long.o

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: ${NAME} libft

libft:
	make -C libft

${NAME}: ${MAIN_OBJ} ${OBJS}
		${CC} ${CFLAGS} ${MAIN_OBJ} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o ${NAME}

clean:
		${RM} ${MAIN_OBJ} ${OBJS}
		make -C libft fclean

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft
