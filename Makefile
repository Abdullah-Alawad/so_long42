NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_checker.c ft_errors.c ft_map_border_checker.c ft_map_parse.c \
		ft_set_game_defaults.c ft_utils1.c

MAIN_SRC = so_long.c

OBJS = ${SRCS:.c=.o}

MAIN_OBJ = ${MAIN_SRC:.c=.o}

all: ${NAME}

${NAME}: ${MAIN_OBJ} ${OBJS} libft
		${CC} ${CFLAGS} ${MAIN_OBJ} ${OBJS} -Llibft -lft -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

libft:
		make -C libft

clean:
		${RM} ${MAIN_OBJ} ${OBJS}
		make -C libft clean

fclean: clean
		${RM} ${NAME} libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft
