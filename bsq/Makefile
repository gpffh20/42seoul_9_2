NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c etc.c find_sq.c free_malloc.c given_map_solve.c input_map_solve.c make_int_map.c
OBJS = $(SRCS:.c=.o)
HDR_DIR = includes
all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(HDR_DIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re