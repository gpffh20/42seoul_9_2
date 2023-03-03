NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC = ./includes

SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = ${addprefix ./srcs/, ${SRC}}
OBJS = ${SRCS:.c=.o}

AR = ar -rc

all: ${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}


clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
