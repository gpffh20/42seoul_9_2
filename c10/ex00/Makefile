NAME = ft_display_file

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

SRCS = main.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${SRCS}
	${CC} ${CFLAGS} -o $@ $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${OBJS}

re : fclean all

.PHONY: all clean fclean re
