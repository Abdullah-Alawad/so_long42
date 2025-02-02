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
		ft_checker_map.c ft_copy_map.c ft_check_solvability.c 

MAIN_SRC = so_long.c

OBJS = ${SRCS:.c=.o}

MAIN_OBJ = ${MAIN_SRC:.c=.o}

%.o:%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $^ -o $@

all: ${NAME}

${NAME}: ${MAIN_OBJ} ${OBJS} libft
		${CC} ${CFLAGS} ${MAIN_OBJ} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o ${NAME}

libft:
		make -C libft

clean:
		${RM} ${MAIN_OBJ} ${OBJS}
		make -C libft clean

fclean: clean
		${RM} ${NAME} libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft
